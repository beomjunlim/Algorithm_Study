#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1000

int n,m,v;
int arr[MAX+1][MAX+1];
bool visited[MAX+1];

void Initialized(){
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
}

void dfs(int x){
    cout<<x<<" ";
    visited[x] = true;

    for(int i=1; i<=n; i++){
        if(arr[x][i]==1&&!visited[i])
            dfs(i);
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    cout<<x<<" ";
    
    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(arr[num][i]==1&&!visited[i]){
                q.push(i);
                visited[i] = true;
                cout<<i<<" ";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>v;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(v);
    cout<<'\n';
    Initialized();
    bfs(v);
}
