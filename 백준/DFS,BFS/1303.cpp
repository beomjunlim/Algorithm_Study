#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100
int n,m;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<m&&0<=y&&y<n;
}

int bfs(int i, int j, char color){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==color){
                cnt++;
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int white = 0;
    int blue = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                if(arr[i][j]=='W')
                    white += pow(bfs(i,j,arr[i][j]),2);
                if(arr[i][j]=='B')
                    blue += pow(bfs(i,j,arr[i][j]),2);
            }
        }
    }

    cout<<white<<" "<<blue<<'\n';
}
