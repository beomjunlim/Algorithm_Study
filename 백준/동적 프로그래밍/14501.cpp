#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX 1500000

int T[MAX+1];
int P[MAX+1];
int dp[MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>T[i]>>P[i];
    }

    dp[0] = 0;

    int max_pay = 0;

    for(int i=0; i<=n; i++){
        dp[i] = max(max_pay, dp[i]);
        if(T[i]+i<=n)
            dp[T[i]+i] = max(dp[i+T[i]], P[i] + dp[i]);
        max_pay = max(max_pay, dp[i]);
    }
    cout<<max_pay;
}
