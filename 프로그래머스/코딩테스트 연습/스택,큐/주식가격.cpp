// https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=cpp#
#include <string>
#include <vector>
#include <queue>
using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<prices.size(); i++){
        q.push(prices[i]);
    }
    
    int idx = 1;
    
    while(!q.empty()){
        int price = 0;
        int num = q.front();
        
        for(int i = idx; i<prices.size(); i++){
            price++;
            if(num>prices[i])
                break;
        }
        idx++;
        q.pop();
        answer.push_back(price);
    }
    return answer;
}
