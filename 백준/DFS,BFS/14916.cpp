#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;


#define MAX 100001
int cnt[MAX];
bool visited[MAX];

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x==0){
            return;
        }
        if(x-5>=0&&!visited[x-5]){
            visited[x-5] = true;
            q.push(x-5);
            cnt[x-5] = cnt[x] + 1;
        }
        if(x-2>=0&&!visited[x-2]){
            visited[x-2] = true;
            q.push(x-2);
            cnt[x-2] = cnt[x] + 1;
        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    bfs(n);
    if(!visited[0])
        cout<<-1;
    else
        cout<<cnt[0];
}
