#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000
int n;
vector<pair<int,int>> v;
vector<int> pay;
int dp[MAX];

int main() {
    cin>>n;
    
    for(int i=0; i<n; i++){
        int s,e,p;
        cin>>s>>e>>p;
        v.push_back(make_pair(s,e));
        pay.push_back(p);
        dp[i] = p;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i].first>v[j].second){
                dp[i] = max(dp[i], dp[j]+pay[i]);
            }
        }
    }
    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}
