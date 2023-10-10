#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,r1,r2,c1,c2;
int arr[MAX][MAX];
int dis[MAX][MAX];
bool visited[MAX][MAX];
int dr[]={-2, -1, 1, 2, 2, 1, -1, -2},dc[]={1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int>> q;

bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<n;
}

void BFS(int r, int c){
    while(!q.empty()){
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();
        if(c_r == r2-1&& c_c == c2-1){
            cout<<dis[r2-1][c2-1]<<'\n';
            break;
        }

        for(int i=0; i<8; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];
            if(InRange(n_r,n_c)&&!visited[n_r][n_c]){
                visited[n_r][n_c] = true;
                dis[n_r][n_c] = dis[c_r][c_c] + 1;
                q.push(make_pair(n_r, n_c));
            }
        }
    }
}

int main() {

    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    q.push(make_pair(r1-1,c1-1));
    visited[r1-1][c1-1] = true;
    
    if(r1==r2&&c1==c2)
        cout<<0<<'\n';
    else{
        BFS(r1-1,c1-1);

        if(dis[r2-1][c2-1]==0)
        cout<<-1<<'\n';
    }

    return 0;
}
