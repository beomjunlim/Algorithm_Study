// https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=cpp
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }
    
    while(!q.empty()){
        if(q.front().first==pq.top()){
            answer++;
            if(q.front().second==location)
                break;
            pq.pop();
            q.pop();
        }
        else{
            int num = q.front().first;
            int index = q.front().second;
            q.pop();
            q.push(make_pair(num,index));
        }
    }
    return answer;
}
