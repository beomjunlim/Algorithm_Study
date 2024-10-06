#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;

int N,L,R;
int arr[51][51];
int temp[51][51];
bool visited[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void bfs(int a, int b, bool &sw) {
	vector<pair<int, int>> Union;
	Union.push_back(make_pair(a, b));

	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = true;

	int sum = arr[a][b];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int num = arr[x][y];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int people = abs(num - arr[nx][ny]);

			if (InRange(nx, ny) && !visited[nx][ny] && people >= L && people <= R) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				Union.push_back(make_pair(nx, ny));
				sum += arr[nx][ny];
			}
		}
	}

	if (Union.size() >= 2)
		sw = true;

	int people = sum / Union.size();

	for (int i = 0; i < Union.size(); i++) {
		int x = Union[i].first;
		int y = Union[i].second;

		temp[x][y] = people;
	}
}

int main() {
	cin >> N >>  L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int time = 0;
	bool sw = false;
	while (1) {
		sw = false;
		memset(visited, false, sizeof(visited));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j, sw);
				}
			}
		}

		if (sw)
			time++;
		else
			break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	cout << time;
	return 0;
}
