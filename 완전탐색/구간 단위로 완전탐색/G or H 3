#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001
int arr[MAX];

int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        char s;
        int a;
        cin>>a>>s;

        if(s=='G')
            arr[a]=1;
        if(s=='H')
            arr[a]=2;
    }

    int max_sum=0;
    for(int i=1; i<=MAX-k+1; i++){
        int sum=0;
        for(int j=i; j<=i+k; j++){
            sum+=arr[j];
        }
        if(max_sum<sum)
            max_sum=sum;
    }
    cout<<max_sum;


    return 0;
}
