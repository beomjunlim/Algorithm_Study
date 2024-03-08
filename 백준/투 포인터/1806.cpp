#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100001
int arr[MAX];
int sum[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,s;
    cin>>n>>s;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int answer = n+1;
    int start = 0;
    int end = 1;

    while(start<=n&&end<=n){
        if(sum[end]-sum[start]<s){
            end++;
        }
        else{
            answer = min(answer, end - start);
            start++;
        }
    }
    if(answer==n+1) answer = 0;
    cout<<answer<<'\n';
}

