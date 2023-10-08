#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX][MAX];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool InRange(int x, int y, int n){
    return (0<x&&x<=n&&0<y&&y<=n);
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>y>>x;
        arr[y][x]=1;
        int num=0;
        for(int j=0; j<4; j++){
            int nx = x +dx[j], ny = y + dy[j];
            if(InRange(nx,ny,n)&&arr[ny][nx]==1)
                num+=1;
        }
        if(num==3)
            cout<<"1"<<'\n';
        else
            cout<<"0"<<'\n';
    }
    return 0;
}
