#include <iostream>
using namespace std;

#define MAX 101

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[]={1,0}, dy[]={0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]==0|| visited[x][y])
        return false;
    return true;
}

void DFS(int x, int y){
    for(int i=0; i<2; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(CanGo(new_x, new_y)){
            visited[new_x][new_y]= 1;
            DFS(new_x, new_y);
        }
    }
}

int main() {
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    DFS(0,0);
    cout<<visited[n-1][m-1];

    return 0;
}
