#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 100001
int n;
int arr[MAX];
int dp[MAX];

void Initialize() {
    for(int i=2; i<=n; i++){
        dp[i] = INT_MIN;
    }
    dp[1] = arr[1];
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    Initialize();

    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    sort(dp+1, dp+n+1);

    cout<<dp[n];
    return 0;
}
