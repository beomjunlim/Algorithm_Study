#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int bfs(long long a, long long b){
    queue<pair<long long, long long>> q;
    q.push(make_pair(a,1));

    while(!q.empty()){
        pair<long long, long long> n = q.front();
        q.pop();

        if(n.first==b)
            return n.second;
        if(n.first*2<=b)
            q.push(make_pair(n.first*2,n.second+1));
        if(n.first*10+1<=b)
            q.push(make_pair(n.first*10 + 1, n.second+1));
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a,b;
    cin>>a>>b;

    cout<<bfs(a,b);
}
