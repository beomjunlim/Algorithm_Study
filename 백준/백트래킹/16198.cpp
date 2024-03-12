#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int ans = 0;

void cnt(vector<int> num, int sum){
    if(num.size()==2){
        ans = max(ans, sum);
        return;
    }

    for(int i=1; i<num.size()-1; i++){
        vector<int> num_copy = num;
        num_copy.erase(num_copy.begin() + i);
        cnt(num_copy, sum + num[i-1] * num[i+1]);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cnt(arr,0);
    cout<<ans<<'\n';
}
