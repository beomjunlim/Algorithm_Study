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
