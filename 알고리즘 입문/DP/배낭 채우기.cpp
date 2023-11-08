#include <iostream>
using namespace std;

#define MAX 10001
int n, m;
int value[MAX];
int weight[MAX];
int dp[MAX][MAX];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        cin >> value[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j>=weight[i])
                dp[i][j] = max(dp[i-1][j - weight[i]] + value[i], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int ans =0;

    for(int i=0; i<=m; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans;
    return 0;
}
