#include <iostream>
using namespace std;

#define MAX 1000

int arr[3] = {1,2,5};
int n;
int dp[MAX];

int main() {
    cin>>n;
    dp[1] = 1;
    dp[2] = 1;
    dp[5] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(i>arr[j])
                dp[i] = (dp[i] + dp[i-arr[j]])%10007;
        }
    }
    cout<<dp[n];
    
    return 0;
}
