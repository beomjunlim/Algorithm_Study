// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp
#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<int> q;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            q.push(1);
        }
        else{
            if(q.empty()){
                answer = false;
                break;
            }
            q.pop();
        }
    }
    
    if(!q.empty())
        answer = false;

    return answer;
}
