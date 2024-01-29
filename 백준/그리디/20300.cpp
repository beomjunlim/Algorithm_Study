#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

#define MAX 10000
long long arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);
    
    int right = n-1;
    int left = 0;
    long long sum = 0;
    
    if(n%2!=0){
        sum = arr[right];
        right--;
    }

    while(right>left){
        long long num = arr[right] + arr[left];
        if(sum<num)
            sum = num;
        right--;
        left++;
    }

    cout<<sum;
}
