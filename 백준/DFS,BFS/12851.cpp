#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


bool visited[200001];
int ans = 0;
int cnt = 0;
bool sw = false;

void bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,0));
    visited[a] = true;

    while(!q.empty()){
        pair<int,int> n = q.front();
        visited[n.first] = true;
        q.pop();

        if(sw&&n.first==b&&n.second==ans){
            cnt++;
        }

        if(!sw&&n.first==b){
            cnt++;
            ans = n.second;
            sw = true;
        }
        
            if(n.first*2<=200000&&!visited[n.first*2])
                q.push(make_pair(n.first*2,n.second+1));
            if(n.first+1<=200000&&!visited[n.first+1])
                q.push(make_pair(n.first+1,n.second+1));
            if(n.first-1>=0&&!visited[n.first-1])
                q.push(make_pair(n.first-1,n.second+1));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin>>a>>b;

    bfs(a,b);
    cout<<ans<<'\n';
    cout<<cnt<<'\n';
}
