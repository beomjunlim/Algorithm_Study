// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end());
    
    int answer = -1;
    do {
        int gauge = k;
        int sum = 0;
        for(auto & it : dungeons){
            if(gauge>=it[0]){
                gauge -= it[1];
                sum += 1;
            }
        }
        answer = max (answer, sum);
    } while(next_permutation(dungeons.begin(), dungeons.end()));

    if(answer == 0)
        answer = -1;
    
    return answer;
}
