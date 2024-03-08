#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coin[11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int answer = 0;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }

    for(int i=n; i>=1; i--){
        answer += k/coin[i];
        k = k%coin[i];
    }

    cout<<answer<<'\n';
}

