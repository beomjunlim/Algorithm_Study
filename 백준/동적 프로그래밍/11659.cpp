#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100001
int dp[MAX];
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i] = dp[i-1] + arr[i];
    }

    while(m>0){
        int a,b;
        cin>>a>>b;
        int answer = dp[b] - dp[a] + arr[a];
        cout<<answer<<'\n';
        m--;
    }
}

