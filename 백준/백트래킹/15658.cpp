#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define MAX 12
int n;
int arr[MAX];
vector<int> ans;

void cnt(int idx, int pls, int mins, int pro, int sub, int num){
    int temp;
    if(idx==n){
        ans.push_back(num);
        return;
    }
    if(pls>0){
        temp = num + arr[idx];
        cnt(idx+1, pls-1, mins, pro, sub, temp);
    }
    if(mins>0){
        temp = num - arr[idx];
        cnt(idx+1, pls, mins-1, pro, sub, temp);
    }  
    if(pro>0){
        temp = num * arr[idx];
        cnt(idx+1, pls, mins, pro-1, sub, temp);
    }
    if(sub>0){
        temp = num / arr[idx];
        cnt(idx+1, pls, mins, pro, sub-1, temp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pls, mins, pro, sub;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cin>>pls>>mins>>pro>>sub;

    cnt(1,pls, mins, pro, sub, arr[0]);

    sort(ans.begin(), ans.end());


    cout<<ans[ans.size()-1]<<'\n';
    cout<<ans[0]<<'\n';
}


