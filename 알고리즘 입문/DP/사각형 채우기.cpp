#include <iostream>
using namespace std;

#define MAX 1001
int dp[MAX];

int main() {
    int n;
    cin>>n;

    dp[1]=0;
    dp[2]=2;
    dp[3]=3;

    for(int i=4; i<=n; i++){
        dp[i] = (dp[i-2]+dp[i-1])%10007;
    }
    cout<<dp[n];
    return 0;
}
