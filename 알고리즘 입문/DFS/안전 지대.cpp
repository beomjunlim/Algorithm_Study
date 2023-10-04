#include <iostream>
using namespace std;

#define MAX 50

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int num;

void InitializeVisited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            visited[i][j]=false;
    }
}

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool CanGo(int x, int y, int k){
    if(!InRange(x,y))
        return false;
    if(visited[x][y]||arr[x][y]<=k)
        return false;
    return true;
}

void DFS(int x, int y, int k){
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(nx,ny,k)){
            visited[nx][ny]=true;
            DFS(nx,ny,k);
        }
    }
}

void GetZoneNum(int k){
    num=0;
    InitializeVisited();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(CanGo(i,j,k)){
                visited[i][j] = true;
                num++;
                DFS(i,j,k);
            }
        }
    }
}

int main() {
    int h=0;
    int ans_num=-1;
    int ans_k=0;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(h<arr[i][j])
                h=arr[i][j];
        }
    }

    for(int k=1; k<=h; k++){
        GetZoneNum(k);

        if(num>ans_num){
            ans_num=num;
            ans_k=k;
        }
    }

    cout<<ans_k<<" "<<ans_num;

    return 0;
}
