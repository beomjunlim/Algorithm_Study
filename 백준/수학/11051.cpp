#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    dp[1][1] = 1;
    dp[1][0] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j==0||i==j) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    cout<<dp[n][k];
}

