#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

struct Eat {
	int cnt, x, y, idx;
};

int n;
int sharkX, sharkY;
int sharkSize = 2;
int arr[21][21];
bool visited[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
map<int, pair<int, int>> fish;

bool cmp(Eat a, Eat b) {
	if (a.cnt == b.cnt) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.cnt < b.cnt;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int x, int y, int num, vector<Eat> &eat) {
	memset(visited, false, sizeof(visited));
	queue < pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(x, y)));
	visited[x][y] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();

		if (sharkX == cx && sharkY == cy) {
			eat.push_back({cnt, x,y,num});
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				if ((arr[nx][ny] != 9 && arr[nx][ny] <= sharkSize) || arr[nx][ny] == 9) {
					visited[nx][ny] = true;
					q.push(make_pair(cnt + 1, make_pair(nx, ny)));
				}
			}
		}
	}
}

int main() {
	cin >> n;

	int idx = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				sharkX = i;
				sharkY = j;
			}
			else if (arr[i][j] != 0) {
				fish[idx] = make_pair(i, j);
				idx++;
			}
		}
	}

	
	int time = 0;
	int sizeUp = 0;

	while (1) {
		vector<Eat> eat;

		if (fish.size() == 0)
			break;

		for (auto it : fish) {
			int idx = it.first;
			int x = it.second.first;
			int y = it.second.second;

			if (arr[x][y] >= sharkSize)
				continue;

			bfs(x, y, idx, eat);
		}

		if (eat.empty())
			break;

		sort(eat.begin(), eat.end(), cmp);

		fish.erase(eat[0].idx);
		arr[eat[0].x][eat[0].y] = 0;
		sharkX = eat[0].x;
		sharkY = eat[0].y;
		sizeUp++;

		if (sizeUp == sharkSize) {
			sizeUp = 0;
			sharkSize++;
		}
		time += eat[0].cnt;
	}

	cout << time;

	return 0;
}
