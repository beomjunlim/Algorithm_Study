#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
int arr[5][5];
bool visited[5][5];
vector<pair<int,int>> node;
int X,Y;
int ans = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void dfs(int x, int y, int idx){
    if(x==node[idx].first&&y==node[idx].second){
        if(idx==m-1){
            ans++;
            return;
        }
        idx++;
    }

    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
            dfs(nx,ny,idx);
        }
    }
    visited[x][y] = false;
}


int main(int argc, char** argv)
{
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        node.push_back({a-1,b-1});
    }

    X = node[0].first;
    Y = node[0].second;
    dfs(X,Y,1);

    cout<<ans;
   return 0;
}
