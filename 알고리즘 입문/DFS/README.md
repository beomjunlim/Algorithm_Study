# 문제
https://inha.codetree.ai/missions/2/problems/graph-traversal/explanation
# 풀이
리스트를 이용해서 DFS를 구현했다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001
vector<int> graph[MAX];
bool visited[MAX];
int n,m;
int cnt=0;

void DFS(int num){
    for(int i=0; i<graph[num].size(); i++){
        int cur_v = graph[num][i];
        if(!visited[cur_v]) {
            cnt += 1;
            visited[cur_v] = true;
            DFS(cur_v);
        }
    }
}


int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited[1] = true;
    DFS(1);
    
    cout<<cnt;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/determine-escapableness-with-2-ways/submissions
# 풀이
방문할 수 있는 지점인지 확인하면서 추가로 방문했던 지점인지 확인하며 스택오버플로우를 방지한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[]={1,0}, dy[]={0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]==0|| visited[x][y])
        return false;
    return true;
}

void DFS(int x, int y){
    for(int i=0; i<2; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(CanGo(new_x, new_y)){
            visited[new_x][new_y]= 1;
            DFS(new_x, new_y);
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

    DFS(0,0);
    cout<<visited[n-1][m-1];

    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/seperate-village/explanation
# 풀이
갈 수 있는 지점인지 아닌지 확인하고 이미 지나간 지점은 bool 배열을 통해 확인한다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 26

int n;
int cnt;
int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool InRange(int i, int j){
    return 0<=i&&i<n&&0<=j&&j<n;
}

void DFS(int i, int j){
    for(int k=0; k<n; k++){
        int ni= i + dx[k];
        int nj= j + dy[k];
        if(!visited[ni][nj]&&InRange(ni,nj)&&arr[ni][nj]==1){
            visited[ni][nj]=true;
            cnt+=1;
            DFS(ni,nj);
        }
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&arr[i][j]==1){
                visited[i][j]=true;
                cnt=1;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/comfort-zone/submissions
# 풀이
이동할 수 있는 경우의 수를 보면서 갈 수 있는 지점인지 아닌지 확인하고 경우를 계산한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 50

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int num;

void InitializeVisited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            visited[i][j]=false;
    }
}

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y, int k){
    if(!InRange(x,y))
        return false;
    if(visited[x][y]||arr[x][y]<=k)
        return false;
    return true;
}

void DFS(int x, int y, int k){
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(nx,ny,k)){
            visited[nx][ny]=true;
            DFS(nx,ny,k);
        }
    }
}

void GetZoneNum(int k){
    num=0;
    InitializeVisited();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(CanGo(i,j,k)){
                visited[i][j] = true;
                num++;
                DFS(i,j,k);
            }
        }
    }
}

int main() {
    int h=0;
    int ans_num=-1;
    int ans_k=0;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(h<arr[i][j])
                h=arr[i][j];
        }
    }

    for(int k=1; k<=h; k++){
        GetZoneNum(k);

        if(num>ans_num){
            ans_num=num;
            ans_k=k;
        }
    }

    cout<<ans_k<<" "<<ans_num;

    return 0;
}
```
