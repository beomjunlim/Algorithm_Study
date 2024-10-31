#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


int n,m;
int ans = 0;
int map[21][21];
bool visited[21][21];
int temp_sum = 0;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool checkBack[3];
int seq[3];

pair<int,int> people[3];
vector<pair<int,int>> path[3];
vector<pair<int,int>> tempPath;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void dfs(int time, int x, int y, int idx){
    if(time==3){
        int sum = 0;
        for(auto it : tempPath){
            sum += map[it.first][it.second];
        }

        if(sum > temp_sum){
            temp_sum = sum;
            path[idx] = tempPath;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&!visited[nx][ny]){
            visited[nx][ny] = true;
            tempPath.push_back({nx,ny});
            dfs(time+1, nx,ny, idx);
            visited[nx][ny] = false;
            tempPath.pop_back();
        }
    }
}

void backtracking(int num){
    if (num==m) {
        int total_sum = 0;
        for(int i=0; i<m; i++){
            visited[people[seq[i]].first][people[seq[i]].second] = true;
            tempPath.push_back({people[seq[i]].first, people[seq[i]].second});

            dfs(0,people[seq[i]].first, people[seq[i]].second, i);

            memset(visited, false, sizeof(visited));
            for(int j=0; j<=i; j++){
                for(auto it : path[j]){
                    visited[it.first][it.second] = true;
                }
            }

            tempPath.clear();
            total_sum += temp_sum;
            temp_sum = 0;
        }

        ans = max(total_sum, ans);
    }
    
    for(int i=0;i<m;i++){
        if(!checkBack[i]){
            checkBack[i] = true;
            seq[num] = i;
            backtracking(num+1);
            checkBack[i] = false;
        }
    }
}


int main(int argc, char** argv)
{
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> map[i][j];

    for(int i=0;i<m;i++){
        int x, y;
        cin >> x;
        cin >> y;
        people[i] = {x-1,y-1};
    }

    backtracking(0);
    cout << ans;
    
   return 0;
}
