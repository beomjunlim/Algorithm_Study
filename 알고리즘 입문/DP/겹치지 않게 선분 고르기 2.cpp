#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int n;
vector<pair<int,int>> v;
int dp[MAX];

bool my_asc(pair<int, int>v, pair<int, int>w){
    return v.second<w.second;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    dp[0] = 1;

    sort(v.begin(), v.end(),my_asc);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[j].second<v[i].first){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    
    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}
