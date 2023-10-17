#include <iostream>
using namespace std;

#define MAX 1000


long long dp[MAX];

int main() {
    int n;
    cin>>n;
    
    dp[0]=1;
    dp[1]=2;
    dp[2]=7;

    for(int i=3; i<=n; i++){
        dp[i]=(2*dp[i-1]+3*dp[i-2])%1000000007;
        for(int j= i-3; j>=0; j--){
            dp[i] = (dp[i] + dp[j]*2)%1000000007;
        }
    }
    cout<<dp[n];
    return 0;
}
