#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100

int n,k;
int cnt = 0;
int arr[MAX+1][MAX+1];
bool visited[MAX+1];

void dfs(int x){
    visited[x] = true;

    for(int i=1; i<=n; i++){
        if(arr[x][i]==1&&!visited[i]){
            cnt++;
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1);
    cout<<cnt;
}
