// https://school.programmers.co.kr/learn/courses/30/lessons/42883?language=cpp
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



string solution(string number, int k) {
    string answer = "";
    int sw = 1;
    
    while(sw){
        for(int i=1; i<number.length(); i++){
            if(number[i-1]<number[i] && k>0){
                number.erase(i-1, 1);
                k--;
                if(k==0)
                    sw = 0;
                break;
            }
            if(i == number.length()-1)
                sw = 0;
        }
    }
    
    while(k--){
        number.erase(number.length()-1, 1);
    }
    answer = number;
    return answer;
}

