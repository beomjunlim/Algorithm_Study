// https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=cpp#
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(-scoville[i]);
    }
    
    while(pq.size()>0){
        if(-pq.top()>=K||pq.size()==1)
            break;
        else if(pq.size()>=2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a+2*b);
            answer++;
        }
    }
    
    if(-pq.top()<K)
        return -1;
    return answer;
}
