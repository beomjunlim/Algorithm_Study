#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num = 0;
int arr[41][41];
int dx[] = {0,0,-1,1};
int dy[] =  {-1,1,0,0};

bool InRange(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<n;
}

void Spread(){
	int temp[41][41];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp[i][j] = arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]!=0){
				int tree = 0;
				for(int k=0; k<4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if(InRange(nx,ny)&&arr[nx][ny]==0)
						tree++;
				}
				temp[i][j] = max(0,arr[i][j] - tree);
				
				if(temp[i][j]==0)
					num--;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = temp[i][j];
		}
	}
}

int main() {	
	cin>>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
			if(arr[i][j]!=0)
				num++;
		}
	}
	
	int time = 0;
	while(num>0){
		time++;
		Spread();
	}
	
	cout<<time;
	
	return 0;
}
