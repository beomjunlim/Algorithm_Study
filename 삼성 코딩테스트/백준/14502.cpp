#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int answer = 0;
int arr[9][9];
bool visited[9][9];
queue<pair<int, int>> virus;
vector<pair<int, int>> blank;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void backtracking(int cnt, int idx) {
	if (cnt == 3) {
		bool spread[9][9] = {false};
		queue<pair<int, int>> q = virus;
		int count = blank.size() - 3;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && !spread[nx][ny] && arr[nx][ny] ==0) {
					spread[nx][ny] = true;
					count--;
					q.push(make_pair(nx, ny));
				}
			}
		}

		answer = max(answer, count);
		return;
	}

	for (int i = idx; i < blank.size(); i++) {
		int x = blank[i].first;
		int y = blank[i].second;

		if (!visited[x][y]) {
			visited[x][y] = true;
			arr[x][y] = 1;
			backtracking(cnt + 1, i + 1);
			arr[x][y] = 0;
			visited[x][y] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2)
				virus.push(make_pair(i, j));
			
			else if (arr[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}

	backtracking(0,0);

	cout << answer;
	return 0;
}
