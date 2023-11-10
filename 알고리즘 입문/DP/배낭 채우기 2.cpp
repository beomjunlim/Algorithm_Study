#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001

int n,m;
int weight[MAX];
int value[MAX];
int dp[MAX][MAX];

void Initialize() {
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = 0;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }

    Initialize();
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j>=weight[i]){
                dp[i][j] = max (dp[i-1][j], dp[i][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}
