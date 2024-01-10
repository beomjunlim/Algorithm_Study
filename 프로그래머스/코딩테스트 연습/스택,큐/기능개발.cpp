// https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i=0; i<progresses.size(); i++){
        int num = 100 - progresses[i];
        int cnt = num/speeds[i];
        if(num%speeds[i]!=0)
            cnt += 1;
        days.push(cnt);
    }
    
    int day = days.front();
    int d = 1;
    
    while(!days.empty()){
        days.pop();
        if(days.empty()){
            answer.push_back(d);
            break;
        }
        if(day>=days.front()){
            d += 1;
        }
        else{
            answer.push_back(d);
            d = 1;
            day = days.front();
        }
    }
    return answer;
}
