#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX 50
int n,m;
int arr[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int ans = 0;
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                ans = max(ans, dist[nx][ny]);
                q.push(make_pair(nx,ny));
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;

    memset(dist, -1, sizeof(dist));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                dist[i][j] = 0;
                visited[i][j] = true;
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();
    cout<<ans;
}
