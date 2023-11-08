#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 10001

int n,m;
int arr[MAX];
bool dp[MAX][MAX];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j >=arr[i] && dp[i -1][j -arr[i]])
                dp[i][j] = true;
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }
    if(dp[n][m])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
