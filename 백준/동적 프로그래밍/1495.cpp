#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX_N 100
#define MAX_M 1010
int arr[MAX_N+1];
int dp[MAX_N+1][MAX_M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,s,m;
    cin>>n>>s>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }


    if(s+arr[1]<=m) dp[1][s+arr[1]] = true;
    if(s-arr[1]>=0) dp[1][s-arr[1]] = true;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(dp[i-1][j]){
                if(j+arr[i]<=m) dp[i][j+arr[i]] = true;
                if(j-arr[i]>=0) dp[i][j-arr[i]] = true;
            }
        }
    }

    int ans = -1;
    for(int i=m; i>=0; i--){
        if(dp[n][i]){
            ans = i;
            break;
        }
    }

    cout<<ans;
}
