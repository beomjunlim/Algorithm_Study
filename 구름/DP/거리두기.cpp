#include <iostream>
#include <algorithm>
using namespace std;

#define SUB 100000007

int dp[100001][5];

int main() {
	int n;
	cin>>n;
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	dp[0][3] = 1;
	dp[0][4] = 1;
	
	for(int i=1; i<n; i++){
		dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%SUB;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4])%SUB;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][4])%SUB;
		dp[i][3] = (dp[i-1][1] + dp[i-1][4])%SUB;
		dp[i][4] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4])%SUB;
	}
	
	int answer = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4])%SUB;
	cout<<answer;
	return 0;
}
