#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n, h, m;
int arr[MAX][MAX];
int cnt[MAX][MAX];
int ans[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;


bool InRange(int r, int c){
    return 0<=r&&r<n&&0<=c&&c<n;
}

bool CanGo(int r, int c){
    return InRange(r,c)&& arr[r][c] !=1 && !visited[r][c];
}

void BFS(){
    while(!q.empty()){
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();

        int dr[]={0,1,0,-1}, dc[]={1,0,-1,0};

        for(int i=0; i<4; i++){
            int n_r = c_r + dr[i];
            int n_c = c_c + dc[i];
            if(CanGo(n_r, n_c)){
                visited[n_r][n_c] = true;
                cnt[n_r][n_c] = cnt[c_r][c_c] + 1;
                q.push(make_pair(n_r, n_c));
            }
        }
    }
}

int main() {
    cin>>n>>h>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==3){
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
         
        }
    }

    BFS();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           if(arr[i][j] !=2)
                cout<<0<<" ";
            else{
                if(!visited[i][j])
                    cout<<-1<<" ";
                else
                    cout<<cnt[i][j]<<" ";
            }    
        }
        cout<<'\n';
    }
    return 0;
}
