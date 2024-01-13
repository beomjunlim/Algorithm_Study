// https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0;
    for(int i=0; i<sizes.size(); i++){
        width = max(width, max(sizes[i][0], sizes[i][1]));
    }
    
    int length = 0;
    for(int i=0; i<sizes.size(); i++){
        length = max(length, min(sizes[i][0], sizes[i][1]));
    }
    
    int answer = 0;
    answer = length*width;
    return answer;
}
