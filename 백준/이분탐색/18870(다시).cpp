#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000000
long long num[MAX];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<long long> tmp;

    for(int i=0; i<n; i++){
        cin>>num[i];
        tmp.push_back(num[i]);
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    for(int i=0; i<n; i++){
        cout<<lower_bound(tmp.begin(), tmp.end(), num[i]) - tmp.begin()<<" ";
    }

}

