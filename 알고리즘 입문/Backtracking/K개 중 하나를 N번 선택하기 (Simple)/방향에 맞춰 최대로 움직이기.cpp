#include <iostream>
using namespace std;

#define MAX 4
int n;
int num;
int dir_num=0;
int cnt=0;
int max_num=0;
int arr[MAX][MAX];
int dir[MAX][MAX];
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={-1,-1,0,1,1,1,0,-1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void Check(int x, int y,int num, int dir_num){
    int nx=x+dx[dir_num];
    int ny=y+dy[dir_num];

    while(InRange(nx,ny)){
        if(num<arr[ny][nx]){
            cnt+=1;
            Check(nx,ny,arr[ny][nx],dir[ny][nx]-1);
            cnt-=1;
        }
        nx=nx+dx[dir_num];
        ny=ny+dy[dir_num];
    }
    max_num = max(max_num,cnt);
}


int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dir[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    dir_num=dir[r-1][c-1];
    num=arr[r-1][c-1];
    Check(c-1,r-1,num,dir_num-1);
    cout<<max_num;
    return 0;
}
