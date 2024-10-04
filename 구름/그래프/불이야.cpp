#include <iostream>
#include <queue>
using namespace std;

int n,m;
int start_x,start_y;
char Map[1001][1001];
int cnt[1001][1001];
bool visited[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>Map[i][j];
			if(Map[i][j]=='&'){
				start_x = i;
				start_y = j;
			}
		}
	}
	
	int answer = -1;
	
	queue<pair<int,int> > q;
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;
	cnt[start_x][start_y] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(Map[x][y]=='@'){
			answer = cnt[x][y] - 1;
			break;
		}
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(InRange(nx,ny)&&Map[nx][ny]!='#'&&!visited[nx][ny]){
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y] + 1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	
	cout<<answer;
	return 0;
}
