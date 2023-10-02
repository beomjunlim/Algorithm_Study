# 문제
https://inha.codetree.ai/missions/2/problems/graph-traversal/explanation
# 풀이
리스트를 이용해서 DFS를 구현했다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001
vector<int> graph[MAX];
bool visited[MAX];
int n,m;
int cnt=0;

void DFS(int num){
    for(int i=0; i<graph[num].size(); i++){
        int cur_v = graph[num][i];
        if(!visited[cur_v]) {
            cnt += 1;
            visited[cur_v] = true;
            DFS(cur_v);
        }
    }
}


int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited[1] = true;
    DFS(1);
    
    cout<<cnt;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/determine-escapableness-with-2-ways/submissions
# 풀이
방문할 수 있는 지점인지 확인하면서 추가로 방문했던 지점인지 확인하며 스택오버플로우를 방지한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[]={1,0}, dy[]={0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]==0|| visited[x][y])
        return false;
    return true;
}

void DFS(int x, int y){
    for(int i=0; i<2; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(CanGo(new_x, new_y)){
            visited[new_x][new_y]= 1;
            DFS(new_x, new_y);
        }
    }
}

int main() {
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    DFS(0,0);
    cout<<visited[n-1][m-1];

    return 0;
}
```
