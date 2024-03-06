#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 101
int n;
int arr[MAX][MAX];
bool visited[MAX];

void dfs(int v){
    for(int i=1; i<=n; i++){
        if(!visited[i]&&arr[v][i]){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        memset(visited, 0, MAX);
        dfs(i);
        for(int j=1; j<=n; j++){
            if(visited[j]) arr[i][j] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}

