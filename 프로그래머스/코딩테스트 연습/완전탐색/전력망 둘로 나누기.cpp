#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int wire[101][101];
bool visited[101];

int bfs(int num, int max_num){
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(num);
    visited[num] = true;
    
    int cnt = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=1; i<=max_num; i++){
            if(wire[node][i]&&!visited[i]){
                cnt++;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i=0; i<wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        
        wire[a][b] = 1;
        wire[b][a] = 1;
    }
    
    for(int i=0; i<wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        
        wire[a][b] = 0;
        wire[b][a] = 0;
        int first = bfs(1,n);
        answer = min(answer, abs(n - 2*first));
        wire[a][b] = 1;
        wire[b][a] = 1;
    }
    return answer;
}
