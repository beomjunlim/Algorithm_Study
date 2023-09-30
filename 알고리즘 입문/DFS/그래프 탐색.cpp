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
