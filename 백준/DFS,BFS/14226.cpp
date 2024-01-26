#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

int visited[1001][1001];
int ans = 0;

int bfs(int x, int a){
    memset(visited, -1, sizeof(visited));
    queue<pair<int,int>> q;
    q.push(make_pair(x,0));
    visited[x][0] = 0;
    int num = 0;

    while(!q.empty()){
        pair<int,int> n = q.front();
        int time = visited[n.first][n.second];
        q.pop();

        if(n.first==a){
            return time;
        }

        if(visited[n.first][n.first]==-1){
            visited[n.first][n.first] = time + 1;
            q.push(make_pair(n.first, n.first));
        }

        if(n.first+n.second<1002&&visited[n.first+n.second][n.second]==-1){
            visited[n.first+n.second][n.second] = time + 1;
            q.push(make_pair(n.first + n.second, n.second));
        }
        
        if(n.first-1>=0 && visited[n.first-1][n.second]==-1){
            visited[n.first-1][n.second] = time + 1;
            q.push(make_pair(n.first-1, n.second)); 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a;
    cin>>a;

    cout<<bfs(1,a);

}
