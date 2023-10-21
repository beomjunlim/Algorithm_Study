#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
int n;
int dp[MAX][MAX];
int arr[MAX][MAX];

void Initialize(){
    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++)
        dp[i][0] = min(dp[i-1][0], arr[i][0]);
    
    for(int i=1; i<n; i++)
        dp[0][i] = min(dp[0][i-1], arr[0][i]);
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    Initialize();

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]),arr[i][j]);
        }
    }

    cout<<dp[n-1][n-1];
    return 0;
}
