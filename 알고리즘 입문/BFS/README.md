# 문제
https://inha.codetree.ai/missions/2/problems/determine-escapableness-with-4-ways/submissions
# 풀이
BFS를 이용해서 주변을 방문하며 탈출 할 수 있는지 확인한다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int x, int y) {
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]!=1||visited[x][y])
        return false;
    return true;
}

void BFS(int x, int y){
    while(!q.empty()){
        int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
        int cx= q.front().first;
        int cy= q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny]=true;
                q.push(make_pair(nx,ny));
            }
        }
    }

}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    visited[0][0] = true;
    q.push(make_pair(0,0));
    BFS(0,0);
    if(visited[n-1][m-1])
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/places-can-go/submissions
# 풀이
시작점을 담기 전에 이미 방문했는지 안했는지 확인을 먼저 하고 cnt를 증가시킨다.
# 코드
```
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
```

# 문제
https://inha.codetree.ai/missions/2/problems/escape-with-min-distance/explanation
# 풀이
거리를 담는 배열을 하나 더 선언해서 BFS를 할 때 마다 거리를 업데이트 해준다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int step[MAX][MAX];
queue<pair<int,int>> q;

bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<m;
}

bool CanGo(int r, int c){
    if(!InRange(r,c))
        return false;
    if(visited[r][c]||arr[r][c]==0)
        return false;
    return true;
}

void BFS(int r, int c){
    q.push(make_pair(r,c));
    step[r][c]=0;
    while(!q.empty()){
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int mr = nr + dr[i];
            int mc = nc + dc[i];
            if(CanGo(mr, mc)){
                visited[mr][mc] = true;
                step[mr][mc] = step[nr][nc]+1;
                q.push(make_pair(mr, mc));
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    visited[0][0] = true;
    BFS(0,0);

    if(visited[n-1][m-1])
        cout<<step[n-1][m-1];
    else
        cout<<-1<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/knight-movements/submissions
# 풀이
시작점이랑 도착점이 같을 경우를 예외로 빼주어서 해주어야 한다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,r1,r2,c1,c2;
int arr[MAX][MAX];
int dis[MAX][MAX];
bool visited[MAX][MAX];
int dr[]={-2, -1, 1, 2, 2, 1, -1, -2},dc[]={1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int>> q;

bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<n;
}

void BFS(int r, int c){
    while(!q.empty()){
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();
        if(c_r == r2-1&& c_c == c2-1){
            cout<<dis[r2-1][c2-1]<<'\n';
            break;
        }

        for(int i=0; i<8; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];
            if(InRange(n_r,n_c)&&!visited[n_r][n_c]){
                visited[n_r][n_c] = true;
                dis[n_r][n_c] = dis[c_r][c_c] + 1;
                q.push(make_pair(n_r, n_c));
            }
        }
    }
}

int main() {

    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    q.push(make_pair(r1-1,c1-1));
    visited[r1-1][c1-1] = true;
    
    if(r1==r2&&c1==c2)
        cout<<0<<'\n';
    else{
        BFS(r1-1,c1-1);

        if(dis[r2-1][c2-1]==0)
        cout<<-1<<'\n';
    }

    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/stay-out-of-rain/submissions
# 풀이
거꾸로 생각해서 도착 지점부터 시작 지점까지 가는 방법을 사용한다.  
도착 지점을 먼저 큐에 삽입하고 그 지점에서 시작 지점까지 갈 수 있는지 거리를 계산한다.
# 코드
```
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n, h, m;
int arr[MAX][MAX];
int cnt[MAX][MAX];
int ans[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;


bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<n;
}

bool CanGo(int r, int c){
    return InRange(r,c)&& arr[r][c] !=1 && !visited[r][c];
}

void BFS(){
    while(!q.empty()){
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();

        int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};

        for(int i=0; i<4; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];
            if(CanGo(n_r, n_c)){
                visited[n_r][n_c] = true;
                cnt[n_r][n_c] = cnt[c_r][c_c] + 1;
                q.push(make_pair(n_r, n_c));
            }
        }
    }
}

int main() {
    cin>>n>>h>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==3){
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
         
        }
    }

    BFS();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           if(arr[i][j] !=2)
                cout<<0<<" ";
            else{
                if(!visited[i][j])
                    cout<<-1<<" ";
                else
                    cout<<cnt[i][j]<<" ";
            }    
        }
        cout<<'\n';
    }
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/remove-k-walls/description
# 풀이
벽을 없애는 과정을 Backtracking을 이용해서 벽을 없애고 그 후 BFS를 이용해서 최단 경로를 구한다.
# 코드
```
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
```

# 문제
https://inha.codetree.ai/missions/2/problems/oranges-have-gone-bad/submissions
# 풀이
상한 귤을 먼저 큐에 담고, 상한 귤에서 나머지로 퍼져 나가는 식으로 문제를 해결한다.
# 코드
```
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
```
