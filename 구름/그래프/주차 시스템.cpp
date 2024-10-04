#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int arr[2001][2001];
bool visited[2001][2001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool InRange(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(int x, int y){
	visited[x][y] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	int cnt = 0;
	
	while(!q.empty()){
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		
		if(arr[nx][ny]==0)
			cnt += 1;
		if(arr[nx][ny]==2)
			cnt -= 2;
		
		for(int i=0; i<4; i++){
			int next_x = nx + dx[i];
			int next_y = ny + dy[i];
			
			if(InRange(next_x, next_y)&&!visited[next_x][next_y]&&arr[next_x][next_y]!=1){
				visited[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
	return cnt;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	
	
	int answer = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]&&arr[i][j]!=1){
				answer = max(answer, bfs(i,j));
			}
		}
	}
	
	
	if(answer<0)
		answer = 0;
	
	cout<<answer;
	return 0;
}
