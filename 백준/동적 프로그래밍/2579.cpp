#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 301
int dp[MAX][3];
int stage[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>stage[i];
    }

    dp[1][1] = stage[1];
    dp[1][0] = 0;

    for(int i=2; i<=n; i++){
        dp[i][2] = dp[i-1][1] + stage[i];
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stage[i];
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
    }

    int answer = max(dp[n][1], dp[n][2]);

    cout<<answer<<'\n';
}

