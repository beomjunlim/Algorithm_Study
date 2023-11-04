#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 10001
int n,m;
int coin[MAX];
int dp[MAX];

int main() {
    cin>>n>>m;

    coin[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }

    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(coin[j]<=i){
                if(dp[i-coin[j]]==INT_MAX)
                    continue;
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }

    int ans = dp[m];
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
