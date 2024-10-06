#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;

int arr[5][8]; // idx 2 R idx 6 L
bool visited[5];

void Move(int num, int dir) {
	visited[num] = true;
	int R = arr[num][2];
	int L = arr[num][6];

	if (dir == 1) {
		int temp = arr[num][7];

		for (int i = 7; i > 0; i--)
			arr[num][i] = arr[num][i - 1];
		
		arr[num][0] = temp;
	}
	else if (dir == -1) {
		int temp = arr[num][0];

		for (int i = 0; i < 7; i++)
			arr[num][i] = arr[num][i + 1];
		
		arr[num][7] = temp;
	}

	if (num < 4&& R != arr[num + 1][6] && !visited[num + 1]) { // R
		Move(num + 1, -dir);
	}

	if (num > 1&& L != arr[num - 1][2] && !visited[num - 1]) { // L
		Move(num - 1, -dir);
	}
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			char a;
			cin >> a;
			arr[i][j] = a - '0';
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int num, dir;
		cin >> num >> dir;
		memset(visited, false, sizeof(visited));
		Move(num,dir);
	}

	int answer = 0;

	for (int i = 1; i <= 4; i++) {
		if (arr[i][0] == 1)
			answer += pow(2, i - 1);
	}

	cout << answer;
	return 0;
}
