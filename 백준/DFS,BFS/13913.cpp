#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;


bool visited[200001];
int parent[200001];
int ans = INT_MAX;
stack<int> s;

void bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,0));
    visited[a] = true;

    while(!q.empty()){
        pair<int,int> n = q.front();
        visited[n.first] = true;
        q.pop();

        if(n.first==b){

            int idx = n.first;
            s.push(idx);
            while(idx!=a){
                idx = parent[idx];
                s.push(idx);
            }
            ans = n.second;
            break;
        }
        
        if(n.first*2<=200000&&!visited[n.first*2]){
            q.push(make_pair(n.first*2,n.second+1));
            visited[n.first*2] = true;
            parent[n.first*2] = n.first;
        }

        if(n.first+1<=200000&&!visited[n.first+1]){
            q.push(make_pair(n.first+1,n.second+1));
            visited[n.first+1] = true;
            parent[n.first+1] = n.first;
        }

        if(n.first-1>=0&&!visited[n.first-1]){
            q.push(make_pair(n.first-1,n.second+1));
            visited[n.first-1] = true;
            parent[n.first-1] = n.first;
        }

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
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}
