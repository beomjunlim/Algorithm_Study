#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001
int n,m;
int arr[MAX];
int dp[MAX];

void Initialize() {
    for(int i=1; i<=m; i++){
        dp[i] = INT_MIN;
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Initialize();
    dp[0] = 0;
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i>=arr[j]){
                if(dp[i - arr[j]] == INT_MIN)
                    continue;
                dp[i] = max (dp[i], dp[i-arr[j]] + 1);
            }
        }
    }

    if(dp[m] == INT_MIN)
        cout<<-1;
    else
        cout<<dp[m];


    return 0;
}
