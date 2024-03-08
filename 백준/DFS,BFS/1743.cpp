#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100

int n,m,k;
int arr[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=m;
}

int bfs(int i, int j){
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

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
                cnt++;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,int>> v;
    cin>>n>>m>>k;

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        v.push_back(make_pair(a,b));
    }

    vector<int> ans;

    for(int i=0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        
        if(!visited[x][y]&&arr[x][y]==1){
            ans.push_back(bfs(x, y));
        }
    }

    sort(ans.begin(), ans.end());

    cout<<ans[ans.size()-1];
}
