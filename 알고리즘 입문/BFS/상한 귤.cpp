#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,k;
int arr[MAX][MAX];
int cnt[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

bool CanGo(int x, int y){
    return InRange(x,y)&&!visited[x][y]&&arr[x][y]==1;
}

void BFS(){
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[cx][cy] + 1; 
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                visited[i][j] = true;
                q.push(make_pair(i,j));
            }
        }
    }

    BFS();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&arr[i][j]!=1)
                cnt[i][j] = -1;
            else if (!visited[i][j]&&arr[i][j]==1)
                cnt[i][j] = -2;
            cout<<cnt[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
