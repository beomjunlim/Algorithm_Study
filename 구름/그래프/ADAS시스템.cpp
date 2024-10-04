#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
char Map[1001][1001];
bool visited[1001][1001];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int px[] = {-1,-1,-1,0,0,1,1,1};
int py[] = {-1,0,1,-1,1,-1,0,1};

bool InRange(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main() {
	cin>>n>>m;
	
	int x,y;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>Map[i][j];
			if(Map[i][j]=='S'){
				x = i;
				y = j;
			}
		}
	}
	
	int answer = 0;
	priority_queue<pair<int,pair<int,int>>> pq;
	visited[x][y] = true;
	
	while(Map[x][y]!='E'){

		
		int next_x = x;
		int next_y = y;

		for(int i=0; i<4; i++){
			int nx = next_x + dx[i];
			int ny = next_y + dy[i];
			
			if(InRange(nx,ny)&&!visited[nx][ny]){
				int num = 0;
				visited[nx][ny] = true;
				if(Map[nx][ny]=='E')
					num = 3;
				else if(Map[nx][ny]=='P')
					num = 2;
				else
					num = 1;
				pq.push(make_pair(num, make_pair(-nx,-ny)));
			}
		}	
		
		x = -pq.top().second.first;
		y = -pq.top().second.second;
		pq.pop();
		
		if(Map[x][y]=='E')
			break;
		
		int num_P = 0;
		
		for(int i=0; i<8; i++){
			int nx = x + px[i];
			int ny = y + py[i];
			
			if(InRange(nx,ny)&&Map[nx][ny]=='P'){
				num_P++;
			}
		}
		
		int warning = 0;
		if(Map[x][y]=='P')
			warning = num_P - 3;
		
		else
			warning = num_P;	
		
		answer += warning;
	}
	
	cout<<max(answer,0);
	return 0;
}
