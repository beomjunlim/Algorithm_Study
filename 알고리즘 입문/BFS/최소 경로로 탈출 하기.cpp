#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int step[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<m;
}

bool CanGo(int r, int c){
    if(!InRange(r,c))
        return false;
    if(visited[r][c]||arr[r][c]==0)
        return false;
    return true;
}

void BFS(int r, int c){
    q.push(make_pair(r,c));
    step[r][c]=0;
    while(!q.empty()){
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int mr = nr + dr[i];
            int mc = nc + dc[i];
            if(CanGo(mr, mc)){
                visited[mr][mc] = true;
                step[mr][mc] = step[nr][nc]+1;
                q.push(make_pair(mr, mc));
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
    BFS(0,0);

    if(visited[n-1][m-1])
        cout<<step[n-1][m-1];
    else
        cout<<-1<<'\n';
    return 0;
}
