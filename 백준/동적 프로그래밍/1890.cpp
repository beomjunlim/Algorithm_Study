#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX 100
int arr[MAX][MAX];
long long dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==n-1&&j==n-1) break;

            int num = arr[i][j];
            if(i+num<n)
                dp[i+num][j] = dp[i+num][j] + dp[i][j];
            if(j+num<n)
                dp[i][j+num] = dp[i][j+num] + dp[i][j];
        }
    }

    cout<<dp[n-1][n-1];
}
