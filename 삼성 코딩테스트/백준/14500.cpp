#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int answer = 0;
int arr[501][501];
bool visited[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		answer = max(answer, sum);
		return;
	}

	if (!visited[x][y]) {
		sum += arr[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)) {
				visited[x][y] = true;
				dfs(nx, ny, cnt + 1, sum);
				visited[x][y] = false;
			}
		}
	}

	if (InRange(x + 1, y + 2)) {
		int temp = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2];

		answer = max(answer, temp - arr[x + 1][y] - arr[x + 1][y + 2]);
		answer = max(answer, temp - arr[x][y] - arr[x][y + 2]);

		
	}

	if (InRange(x + 2, y + 1)) {
		int temp = arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y] + arr[x + 2][y + 1];
		answer = max(answer, temp - arr[x][y] - arr[x + 2][y]);
		answer = max(answer, temp - arr[x][y + 1] - arr[x + 2][y + 1]);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j,0,0);
		}
	}

	cout << answer;
	return 0;
}
