#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> num(n);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    for(int i=0; i<n; i++){
        cout<<num[i]<<'\n';
    }
}

