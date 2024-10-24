#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int K, N;
long long arr[10001];
int main() {
	cin >> K >> N;
	long long maxNum = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		maxNum = max(maxNum, arr[i]);
	}

	sort(arr, arr + K);

	long long answer = 0;
	long long left = 1;
	long long right = maxNum;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long ans = 0;
		for (int i = 0; i < K; i++) {
			ans += arr[i] / mid;
		}

		if (ans >= N) {
			left = mid + 1;
			answer = max(answer, mid);
		}
		else {
			right = mid - 1;
		}
		
	}
	cout << answer;
}
