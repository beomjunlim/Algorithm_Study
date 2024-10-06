#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

// R 0 U 1 L 2 D 3

int n;
int answer = 0;
int arr[21][21];
int temp[21][21];
int ans[5];

void backtracking(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		for (int k = 0; k < 5; k++) {
			if (ans[k] == 0) { //R
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = n - 1; j >= 0; j--) {
						q.push(temp[i][j]);
					}
					queue<int> after;
					int idx = n - 1;
					while (!q.empty()) {
						int num = q.front();
						q.pop();

						if (num != 0) {
							if (after.empty())
								after.push(num);
							else {
								int number = after.front();
								after.pop();
								if (number == num)
									number += num;
								else
									after.push(num);
								temp[i][idx] = number;
								idx--;
							}
						}
					}

					if (!after.empty()) {
						temp[i][idx] = after.front();
						after.pop();
						idx--;
					}
					for (int j = idx; j >= 0; j--)
						temp[i][j] = 0;
				}
			}
			else if (ans[k] == 1) { // L
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j =0; j <n; j++) {
						q.push(temp[i][j]);
					}
					queue<int> after;
					int idx = 0;
					while (!q.empty()) {
						int num = q.front();
						q.pop();

						if (num != 0) {
							if (after.empty())
								after.push(num);
							else {
								int number = after.front();
								after.pop();
								if (number == num)
									number += num;
								else
									after.push(num);
								temp[i][idx] = number;
								idx++;
							}
						}
					}

					if (!after.empty()) {
						temp[i][idx] = after.front();
						after.pop();
						idx++;
					}

					for (int j = idx; j <n; j++)
						temp[i][j] = 0;
				}
			}
			else if (ans[k] == 2) { // D
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = n - 1; j >= 0; j--) {
						q.push(temp[j][i]);
					}
					queue<int> after;
					int idx = n - 1;
					while (!q.empty()) {
						int num = q.front();
						q.pop();

						if (num != 0) {
							if (after.empty())
								after.push(num);
							else {
								int number = after.front();
								after.pop();
								if (number == num)
									number += num;
								else
									after.push(num);
								temp[idx][i] = number;
								idx--;
							}
						}
					}
					if (!after.empty()) {
						temp[idx][i] = after.front();
						after.pop();
						idx--;
					}

					for (int j = idx; j >= 0; j--)
						temp[j][i] = 0;
				}
			}
			else if (ans[k] == 3) { // U
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = 0; j < n; j++) {
						q.push(temp[j][i]);
					}
					queue<int> after;
					int idx = 0;
					while (!q.empty()) {
						int num = q.front();
						q.pop();

						if (num != 0) {
							if (after.empty())
								after.push(num);
							else {
								int number = after.front();
								after.pop();
								if (number == num)
									number += num;
								else
									after.push(num);
								temp[idx][i] = number;
								idx++;
							}
						}
					}

					if (!after.empty()) {
						temp[idx][i] = after.front();
						after.pop();
						idx++;
					}

					for (int j = idx; j < n; j++)
						temp[j][i] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer = max(answer, temp[i][j]);
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		ans[cnt] = i;
		backtracking(cnt + 1);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	backtracking(0);
	cout << answer;
	return 0;
}
