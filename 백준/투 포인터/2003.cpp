#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10000
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i = 0;
    int j = 1;
    int ans = 0;
    int tmp = arr[0];

    while(j<=n){
        if(tmp==m){
            ans++;
            tmp -= arr[i];
            i++;
        }
        else if(tmp<m){
            tmp += arr[j];
            j++;
        }
        else{
            tmp -= arr[i];
            i++;
        }
    }
    cout<<ans<<'\n';
}
