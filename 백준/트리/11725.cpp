#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100001
vector<int> arr[MAX];
int num[MAX];
bool visited[MAX];

void dfs(int x){
    visited[x] = true;

    for(int i=0; i<arr[x].size(); i++){
        if(!visited[arr[x][i]]){
            num[arr[x][i]] = x;
            dfs(arr[x][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    dfs(1);

    for(int i=2; i<=n; i++){
        cout<<num[i]<<'\n';
    }
}

