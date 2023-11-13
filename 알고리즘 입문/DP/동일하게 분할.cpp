#include <iostream>
using namespace std;

#define MAX 100000
int n;
int arr[101];
bool dp[101][MAX+1];

int main() {
    cin>>n;
    int sum = 0;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j>=arr[i] && dp[i-1][j-arr[i]])
                dp[i][j] = true;
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    if(sum%2==0&&dp[n][sum/2]){
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    
    return 0;
}
