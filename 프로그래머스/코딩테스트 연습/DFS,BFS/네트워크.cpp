// https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=cpp#
#include <string>
#include <vector>

using namespace std;

#define MAX 200
bool visited[MAX];

void dfs(vector<vector<int>> computers, int n){
    for(int i=0; i<computers[n].size(); i++){
        if(computers[n][i]==1&&!visited[i]){
            visited[i] = true;
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(visited[i])
            continue;
        else {
            visited[i] = true;
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}
