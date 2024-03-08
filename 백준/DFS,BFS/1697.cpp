#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9

int graph[100002];
bool visited[100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,x;
    cin>>n>>k;

    queue<int> q;
    q.push(n);
    graph[n] = 0;
    visited[n] = true;

    while(!q.empty()){
        x = q.front();
        q.pop();

        if(x==k){
            cout<<graph[k]<<'\n';
            break;
        }

        if(x-1>=0&&!visited[x-1]){
            q.push(x-1);
            visited[x-1] = true;
            graph[x-1] = graph[x] + 1;
        }

        if(x+1<=100002&&!visited[x+1]){
            q.push(x+1);
            visited[x+1] = true;
            graph[x+1] = graph[x] + 1;
        }

        if(x*2<=100002&&!visited[x*2]){
            q.push(x*2);
            visited[x*2] = true;
            graph[x*2] = graph[x] + 1;
        }
    }
}
