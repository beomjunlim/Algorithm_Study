#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000
int dp[MAX][3];
int house[MAX][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>house[i][j];
        }
    }

    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }

    cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

