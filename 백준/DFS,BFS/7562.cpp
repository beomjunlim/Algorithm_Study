#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 300
bool visited[MAX][MAX];
int answer[MAX][MAX];

int dx[] = {-1,-1,-2,-2,1,1,2,2};
int dy[] = {-2,2,-1,1,-2,2,-1,1};

bool InRange(int m, int x, int y){
    return 0<=x&&x<m&&0<=y&&y<m;
}

int bfs(int m, int sx, int sy, int ex, int ey){
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    visited[sx][sy] = true;
    answer[sx][sy] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x==ex&&y==ey)
            return answer[x][y];
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(m,nx,ny)&&!visited[nx][ny]){
                answer[nx][ny] = answer[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    while(n>0){
        int m;
        cin>>m;
        int sx,sy,ex,ey;
        cin>>sx>>sy;
        cin>>ex>>ey;

        cout<<bfs(m,sx,sy,ex,ey)<<'\n';
        memset(answer, 0, sizeof(answer));
        memset(visited, false, sizeof(visited));
        n--;
    }
}
