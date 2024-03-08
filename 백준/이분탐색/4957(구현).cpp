#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100000
int arr[MAX];
int n,m;

bool binaryFunction(int num){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid_idx = (start + end) / 2;
        if(num==arr[mid_idx])
            return true;
        if(num>arr[mid_idx]){
            start = mid_idx+1;
        }
        else{
            end = mid_idx-1;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    cin>>m;

    for(int i=0; i<m; i++){
        int num;
        cin>>num;
        if(binaryFunction(num)) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}

