# 문제
https://inha.codetree.ai/missions/2/problems/determine-escapableness-with-4-ways/submissions
# 풀이
BFS를 이용해서 주변을 방문하며 탈출 할 수 있는지 확인한다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int x, int y) {
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]!=1||visited[x][y])
        return false;
    return true;
}

void BFS(int x, int y){
    while(!q.empty()){
        int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
        int cx= q.front().first;
        int cy= q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny]=true;
                q.push(make_pair(nx,ny));
            }
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

    visited[0][0] = true;
    q.push(make_pair(0,0));
    BFS(0,0);
    if(visited[n-1][m-1])
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/places-can-go/submissions
# 풀이
시작점을 담기 전에 이미 방문했는지 안했는지 확인을 먼저 하고 cnt를 증가시킨다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
int n,k;
int cnt=0;
int arr[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(visited[x][y]||arr[x][y]==1)
        return false;
    return true;
}

void BFS(int x, int y){
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny]=true;
                cnt+=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}


int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int x,y;
        cin>>x>>y;
        q.push(make_pair(x-1,y-1));
        if(!visited[x-1][y-1])
            cnt+=1;
        visited[x-1][y-1]=true;
        BFS(x-1,y-1);
    }
    cout<<cnt<<'\n';
    return 0;
}
```
