#include <iostream>
using namespace std;

#define MAX 46

int dp[MAX];
int memo[MAX];

int fibo(int n){
    if(n<=2)
        return 1;

    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibo2(int n){
    if(memo[n] != 0)
        return memo[n];
    if(n<=2)
        memo[n] = 1;
    else
        memo[n] = fibo2(n-1) + fibo2(n-2);
    return memo[n];
}

int main() {
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    cout<<fibo2(n);
    return 0;
}
