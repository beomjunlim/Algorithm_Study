#include <iostream>
using namespace std;

#define MAX 100

int n;
int cnt;
int arr[MAX][MAX];
bool visited[MAX][MAX];

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

bool CanGo(int x, int y, int num){
    if(!InRange(x,y))
        return false;
    if(arr[x][y]!=num||visited[x][y])
        return false;
    return true;
}

void DFS(int x, int y){
    int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
    int num = arr[x][y];

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(CanGo(nx,ny,num)){
            cnt+=1;
            visited[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}



int main() {
    int ans=0;
    int blk=0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                visited[i][j]=true;
                cnt=1;
                DFS(i,j);
                if(ans<cnt)
                    ans=cnt;
                if(cnt>=4)
                    blk+=1;
            }
        }
    }
    cout<<blk<<" "<<ans;

    return 0;
}
