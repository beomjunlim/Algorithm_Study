#include<iostream>

using namespace std;

int H,W;
char arr[21][21];

bool InRange(int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>H>>W;
        int x, y;
        for(int i=0; i<H; i++){
        	for(int j=0; j<W; j++){
            	cin>>arr[i][j];
                if(arr[i][j]=='<'||arr[i][j]=='>'||arr[i][j]=='^'||arr[i][j]=='v'){
                	x = i;
                    y = j;
                }
            }
        }
        
        int n;
        cin>>n;
        string str;
        cin>>str;
        
        for(int i=0; i<n; i++){
        	if(str[i]=='U'){
                if(InRange(x-1,y)&&arr[x-1][y]=='.'){
                    arr[x][y] = '.';
                    x--;
                }
                arr[x][y] = '^';
            }
            else if(str[i]=='D'){
                if(InRange(x+1,y)&&arr[x+1][y]=='.'){
                	arr[x][y] = '.';
                    x++;
                }
                arr[x][y] = 'v';
            }
            else if(str[i]=='L'){
                if(InRange(x,y-1)&&arr[x][y-1]=='.'){
                	arr[x][y] = '.';
                    y--;
                }
                arr[x][y] = '<';
            }
            else if(str[i]=='R'){
                if(InRange(x,y+1)&&arr[x][y+1]=='.'){
                	arr[x][y] = '.';
                    y++;
                }
                arr[x][y] = '>';
            }
            else if(str[i]=='S'){
                if(arr[x][y]=='^'){
                    for(int j=x; j>=0; j--){
                        if(arr[j][y]=='*'||arr[j][y]=='#'){
                            if(arr[j][y]=='*'){
                                arr[j][y]='.';
                            }
                            break;
                        }
                    }
                }
                else if(arr[x][y]=='v'){
                	for(int j=x; j<H; j++){
                        if(arr[j][y]=='*'||arr[j][y]=='#'){
                            if(arr[j][y]=='*'){
                                arr[j][y]='.';
                            }
                            break;
                        }
                    }
                }
                else if(arr[x][y]=='<'){
                for(int j=y; j>=0; j--){
                        if(arr[x][j]=='*'||arr[x][j]=='#'){
                            if(arr[x][j]=='*'){
                                arr[x][j]='.';
                            }
                            break;
                        }
                    }
                }
                else if(arr[x][y]=='>'){
                	for(int j=y; j<W; j++){
                        if(arr[x][j]=='*'||arr[x][j]=='#'){
                            if(arr[x][j]=='*'){                    
                                arr[x][j]='.';
                            }
                            break;
                        }
                    }
                }
            }
        }
		cout<<"#"<<test_case<<" ";
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    cout<<arr[i][j];
                }
                cout<<'\n';
            }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
