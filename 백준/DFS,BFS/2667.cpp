#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int graph[25][25];
vector<int> v;
int room;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y) {
	graph[x][y]=0;
	room++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (graph[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &graph[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				room = 0;
				dfs(i, j);
				v.push_back(room);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
