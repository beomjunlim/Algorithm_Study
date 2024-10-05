#include<iostream>
#include<queue>
using namespace std;

int n, m,end_x,end_y,red_x,red_y,blue_x,blue_y;
char arr[11][11];
bool visited[11][11][11][11];
int dx[] = { 0,0,-1,1 }; // 0 : U 1 : D 2 : L 3 : R
int dy[] = { -1,1,0,0 };

bool sw = false;
int answer = 0;

struct Ball {
	int red_x, red_y, blue_x, blue_y, cnt;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void move(int &x, int &y, int dir, int& cnt) {
	cnt = 0;
	
	while (1) {
		if (arr[x][y] == 'O')
			break;

		if (arr[x + dx[dir]][y + dy[dir]] == '#')
			break;

		x += dx[dir];
		y += dy[dir];
		cnt++;
	}
}


void bfs() {
	queue<Ball> q;
	q.push({ red_x,red_y,blue_x,blue_y,0 });
	visited[red_x][red_y][blue_x][blue_y] = true;

	while (!q.empty()) {
		int cnt = q.front().cnt;
		int rx = q.front().red_x;
		int ry = q.front().red_y;
		int bx = q.front().blue_x;
		int by = q.front().blue_y;
		q.pop();

		if (cnt > 10) break;
		if (bx == end_x && by == end_y) continue;
		if (rx == end_x && ry == end_y) {
			sw = true;
			answer = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;
			int red_cnt = 0, blue_cnt = 0;

			move(n_rx, n_ry, i,red_cnt);
			move(n_bx, n_by, i, blue_cnt);

			if (n_rx == n_bx && n_ry == n_by) {
				if (arr[n_rx][n_ry] != 'O') {
					if (red_cnt > blue_cnt) {
						n_rx -= dx[i];
						n_ry -= dy[i];
					}
					else {
						n_bx -= dx[i];
						n_by -= dy[i];
					}
				}
			}

			if (!visited[n_rx][n_ry][n_bx][n_by]) {
				visited[n_rx][n_ry][n_bx][n_by] = true;
				q.push({ n_rx, n_ry, n_bx, n_by, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}

			if (arr[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}

			if (arr[i][j] == 'O') {
				end_x = i;
				end_y = j;
			}
		}
	}

	bfs();

	if (!sw)
		answer = -1;

	cout << answer << '\n';
	return 0;
}

