#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1000

int arr[MAX][MAX];
bool visited[MAX][MAX];
int myCount[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m;


bool InRange(int x, int y){
    return 0<=x&&x<m&&0<=y&&y<n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int cnt = 0;
    queue<pair<int,int>> q;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==0)
                cnt++;
            if(arr[i][j]==1){
                q.push(make_pair(i,j));
                myCount[i][j] = 0;
            }

        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(InRange(nx,ny)&&arr[nx][ny]==0&&!visited[nx][ny]){
                myCount[nx][ny] = myCount[x][y] + 1;
                cnt--;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                answer = myCount[nx][ny];
            }
        }
    }

    if(cnt!=0)
        cout<<-1<<'\n';
    else
        cout<<answer<<'\n';
}
