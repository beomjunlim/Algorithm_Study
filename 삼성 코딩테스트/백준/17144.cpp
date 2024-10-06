#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int n, m, t;
int sum = 0, UP = 0, DOWN = 0;
int arr[51][51];
int temp[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool InRange(int x, int y) {
	return 0 < x && x <= n && 0 < y && y <= m;
}

void spread() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > 0) {
				int num = arr[i][j] / 5;
				int count = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (InRange(x, y) && arr[x][y] != -1) {
						count++;
						temp[x][y] += num;
					}
				}

				temp[i][j] -= num * count;
			}
		}
	}
}

void window() {
	sum -= temp[UP - 1][1];
	
	for (int i = UP - 1; i > 1; i--) {
		temp[i][1] = temp[i - 1][1];
	}

	for (int i = 1; i <m; i++) {
		temp[1][i] = temp[1][i + 1];
	}

	for (int i = 1; i < UP; i++) {
		temp[i][m] = temp[i + 1][m];
	}

	for (int i = m; i > 2; i--) {
		temp[UP][i] = temp[UP][i - 1];
	}

	temp[UP][2] = 0;

	sum -= temp[DOWN + 1][1];

	for (int i = DOWN + 1; i < n; i++) {
		temp[i][1] = temp[i + 1][1];
	}

	for (int i = 1; i < m; i++) {
		temp[n][i] = temp[n][i + 1];
	}

	for (int i = n; i > DOWN; i--) {
		temp[i][m] = temp[i - 1][m];
	}

	for (int i = m; i > 2; i--) {
		temp[DOWN][i] = temp[DOWN][i - 1];
	}

	temp[DOWN][2] = 0;
}

int main() {
	cin >> n >> m >> t;
	bool sw = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1 && !sw) {
				sw = true;
				UP = i;
			}
			else if (arr[i][j] == -1)
				DOWN = i;
			else if (arr[i][j] != 0) {
				sum += arr[i][j];
			}
		}
	}

	while (t > 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		spread();
		
		window();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				arr[i][j] = temp[i][j];
			}

		}

		t--;
	}

	cout << sum;
	return 0;
}
