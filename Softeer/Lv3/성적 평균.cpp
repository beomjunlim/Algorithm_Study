#include<iostream>
#include<iomanip>
using namespace std;

int arr[1000001];
int sum[1000001];

int main(int argc, char** argv)
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        double ans = sum[b] - sum[a] + arr[a];
        cout<<fixed<<setprecision(2)<<ans/(b-a+1)<<'\n';
    }
   return 0;
}
