#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000001
int dp[MAX];
int pre[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    dp[1] = 0;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        pre[i] = i-1;
        if(i%2==0&& dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            pre[i] = i/2;
        }
        if(i%3==0&& dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            pre[i] = i/3;
        }
    }

    cout<<dp[n]<<'\n';

    while(1){
        cout<<n<<" ";
        if(n==1)
            break;
        n = pre[n];   
    }
}

