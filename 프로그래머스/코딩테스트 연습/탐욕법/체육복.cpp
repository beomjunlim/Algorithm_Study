// https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=cpp
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define MAX 30

bool student[MAX] = {false,};

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int answer = n - lost.size();
    unordered_set<int> num;
    
    for(int i=0; i<reserve.size(); i++){
        num.insert(reserve[i]);    
    }
    
    for(int i=0; i<lost.size(); i++){
        if(num.find(lost[i])!=num.end()){
            num.erase(lost[i]);
            answer++;
            student[i] = true;
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        if(student[i])
            continue;
        if(num.find(lost[i]-1)!=num.end()){
            num.erase(lost[i]-1);
            answer++;
            continue;
        }
        else if(num.find(lost[i]+1)!=num.end()){
            num.erase(lost[i]+1);
            answer++;
            continue;
        }
    }
    
    return answer;
}
