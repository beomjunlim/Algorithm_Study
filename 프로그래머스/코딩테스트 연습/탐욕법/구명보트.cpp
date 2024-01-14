// https://school.programmers.co.kr/learn/courses/30/lessons/42885?language=cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), compare);
    
    int num = people.size();
    
    int right = 0;
    int left = num-1;
    int answer = 0;
    
    while(num>0){
        if(right==left){
            answer++;
            break;
        }
        if(people[right] + people[left] <= limit){
            right++;
            left--;
            num-=2;
            answer++;
        }
        else{
            right++;
            num-=1;
            answer++;
        }
    }

    return answer;
}
