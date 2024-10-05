#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, k, l;
int arr[101][101];
int dx[] = {0,-1,0,1}; 
int dy[] = { 1,0,-1,0 };

bool InRange(int x, int y) {
	return 0 < x && x <= n && 0 < y && y <= n;
}

int main() {
	cin >> n>>k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	queue<pair<int, char>> command;
	cin >> l;

	for (int i = 0; i < l; i++) {
		int t;
		char d;
		cin >> t >> d;
		command.push(make_pair(t, d));
	}


	deque<pair<int, int>> snake;
	snake.push_back(make_pair(1, 1));
	int dir = 0;
	arr[1][1] = 5;
	int time = 0;

	while (1) {
		if (!command.empty()&&time==command.front().first) {
			if (command.front().second == 'L')
				dir = (dir + 1) % 4;
			else if (command.front().second == 'D')
				dir = (dir + 3) % 4;
			command.pop();	
		}

		time++;
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];
		
		if (!InRange(nx, ny)||arr[nx][ny]==5)
			break;
		
		if (arr[nx][ny] == 0) {
			arr[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		arr[nx][ny] = 5;
		snake.push_front(make_pair(nx, ny));
	}

	cout << time;
	return 0;
}
