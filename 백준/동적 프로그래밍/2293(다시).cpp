#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_N 100
#define MAX_K 10000

int arr[MAX_N];
int dp[MAX_K+1];
int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(arr[i]<=j)
                dp[j] += dp[j-arr[i]];
        }
    }

    cout<<dp[k];

}
