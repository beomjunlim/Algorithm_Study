// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int width, length;
    int sum = brown + yellow;
    
    for(int i=3; i<=sum; i++){
        int j;
        if(sum%i==0){
            j = sum/i;
            if((i-2)*(j-2)==yellow){
                width = max(i,j);
                length = min(i,j);
                break;
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(width);
    answer.push_back(length);
    return answer;
}
