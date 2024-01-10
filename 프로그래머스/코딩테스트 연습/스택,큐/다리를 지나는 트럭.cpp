// https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=cpp#
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int answer = 0;
    int sum = 0;
    int idx = 0;
    
    while(1){
        if(idx==truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        answer ++;
        int num = truck_weights[idx];
        
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        
        if(sum + num <= weight){
            sum += num;
            q.push(num);
            idx++;
        } else{
            q.push(0);
        }  
    }
    return answer;
}
