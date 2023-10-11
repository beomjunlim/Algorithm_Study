#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int n, k, r1, r2, c1, c2;
int arr[MAX][MAX];
int cnt[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> v;
vector<int> ans;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void Initialized(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            cnt[i][j] = 0;
        }
    }
}

void BFS(){
    queue<pair<int,int>>q;
    q.push(make_pair(r1-1,c1-1));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==r2-1&&y==c2-1){
            ans.push_back(cnt[x][y]);
            break;
        }

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1 ,0};
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void BackT(int num, int start){
    if(num==k){
        BFS();
        Initialized();
        return;
    }

    for(int i=start; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        arr[x][y] = 0;
        BackT(num+1, start+1);
        arr[x][y] = 1;
    }
}



int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)
                v.push_back(make_pair(i,j));
        }
    }

    cin>>r1>>c1>>r2>>c2;

        BackT(0,0);
        if(ans.empty())
            cout<<-1<<'\n';
        else{
            sort(ans.begin(), ans.end());
            cout<<ans.front()<<'\n';
        }
        
    return 0;
}
