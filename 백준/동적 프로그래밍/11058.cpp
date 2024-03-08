#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX 101
long long dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    int cnt = 0;

    for(int i=4; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        for(int j=3; j<i; j++){
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }

    cout<<dp[n];
}
