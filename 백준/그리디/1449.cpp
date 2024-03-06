#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l;
    cin>>n>>l;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int idx = arr[0] + l - 1;
    int ans = 1;
    
    for(int i=1; i<arr.size(); i++){
        if(idx>=arr[i])
            continue;
        else{
            ans++;
            idx = arr[i] + l - 1;
        }
    }

    cout<<ans<<'\n';
}

