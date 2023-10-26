#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 1000

int arr[MAX+1];
int dp[MAX+1];
int n;

void Initialize(){
    for(int i=0; i<=n; i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    arr[0] = 0;
}

int main() {

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    Initialize();
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans=0;

    for(int i=0; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans;

    return 0;
}
