#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100001
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+n, greater<>());
    int answer = arr[0];
    
    for(int i=0; i<n; i++){
        answer = max(answer, arr[i]*(i+1));
    }

    cout<<answer<<'\n';
}

