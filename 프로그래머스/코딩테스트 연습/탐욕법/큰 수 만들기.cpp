// https://school.programmers.co.kr/learn/courses/30/lessons/42883?language=cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    
    int idx = 1;
    while(1){
        if(number[idx-1]<number[idx]&&k>0){
            number.erase(idx-1,1);
            k--;
            if(idx!=1)
                idx--;
            if(k==0)
                break;
        }else{
            idx++;
            if(idx==number.length())
                break;
        }
    }
    
    while(k>0){
        number.erase(number.length()-1,1);
        k--;
    }
    
    answer = number;
    return answer;
}
