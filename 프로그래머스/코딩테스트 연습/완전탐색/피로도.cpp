// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[10];
int arr[10];
int answer = -1;

void backtracking(int cnt, vector<vector<int>> dungeons, int k){
    if(cnt==dungeons.size()){
        int tmp = 0;
        for(int i=0; i<cnt; i++){
            int start = dungeons[arr[i]][0];
            int minus = dungeons[arr[i]][1];
            
            if(k>=start){
                tmp++;
                k -= minus;
            }
            else
                break;
        }
        answer = max(answer, tmp);
        return;
    }
    
    for(int i=0; i<dungeons.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            backtracking(cnt+1, dungeons, k);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    backtracking(0,dungeons, k);
    return answer;
}
