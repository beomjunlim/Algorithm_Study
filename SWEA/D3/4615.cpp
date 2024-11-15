#include<iostream>

using namespace std;

int n,m;
int arr[10][10];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=n;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>n>>m;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = 0;
            }
        }
        
        int num = n/2;
        arr[num][num] = 2;
        arr[num][num+1] = 1;
        arr[num+1][num] = 1;
        arr[num+1][num+1] = 2;
        
        for(int i=0; i<m; i++){
            int x,y,rock;
            cin>>x>>y>>rock;

            arr[x][y] = rock;
            int num;
            if(rock==1)
                num = 2;
            else
                num = 1;
            
            for(int j=0; j<8; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(InRange(nx,ny)&&arr[nx][ny]==num){
                	int cr = nx;
                    int cy = ny;
                    bool sw = false;
                    int cnt = 1;
                    while(1){
                    	cr = nx + cnt*dx[j];
                        cy = ny + cnt*dy[j];
                        if(!InRange(cr,cy))
                            break;
                        if(arr[cr][cy]!=num){
                            if(arr[cr][cy]==rock)
                                sw = true;
                        	break;
                        }
                        cnt++;
                    }
					if(sw){
                        for(int k=0; k< cnt; k++){
                            arr[nx+k*dx[j]][ny+k*dy[j]] = rock;
                        }
                    }
                }
            }
        }
        
        int black = 0;
        int white = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j]==1)
                    black++;
                if(arr[i][j]==2)
                    white++;
            }
        }
        cout<<"#"<<test_case<<" "<<black<<" "<<white<<'\n';
                        

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
