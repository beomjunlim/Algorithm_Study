#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, x, y, k;
int Map[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int dice[6];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int command;
		cin >> command;
		command--;

		int nx = x + dx[command];
		int ny = y + dy[command];

		if (InRange(nx, ny)) {
			vector<int> temp;
			if (command == 0)
				temp = { dice[2], dice[3], dice[1], dice[0], dice[4], dice[5] };
			else if (command == 1)
				temp = { dice[3], dice[2], dice[0], dice[1], dice[4], dice[5] };
			else if (command == 2)
				temp = { dice[5], dice[4], dice[2], dice[3], dice[0], dice[1] };
			else if (command == 3)
				temp = { dice[4], dice[5], dice[2],dice[3], dice[1],dice[0] };

			if (Map[nx][ny] != 0) {
				temp[1] = Map[nx][ny];
				Map[nx][ny] = 0;
			}
			else
				Map[nx][ny] = temp[1];

			for (int i = 0; i < 6; i++)
				dice[i] = temp[i];

			x = nx;
			y = ny;
			cout << dice[0] << '\n';
		}
	}
	return 0;
}
