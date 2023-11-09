#include <iostream>
using namespace std;

#define MAX 10001
int n;
int arr[MAX];
int dp[MAX];

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[0] = 0;

    for(int i=1; i<=n; i++){
        dp[i] = arr[i];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }
    
    cout<<dp[n];
    return 0;
}
