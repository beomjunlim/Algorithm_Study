#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100000
int arr[MAX];
int n,m;


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
        bool sw = binary_search(arr, arr+n, num);
        if(sw)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
}

