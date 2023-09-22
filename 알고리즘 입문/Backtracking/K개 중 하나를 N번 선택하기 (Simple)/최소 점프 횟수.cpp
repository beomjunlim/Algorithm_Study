#include <iostream>
using namespace std;

#define MAX 10
int n;
int arr[MAX];
int cnt=0;
int min_num =100;

void Check(int num){
    if(num==n-1){
        min_num = min(min_num,cnt);
    }
    for(int i=1; i<=arr[num]; i++){
        cnt+=1;
        Check(num+i);
        cnt-=1;
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Check(0);
    if(min_num!=100)
        cout<<min_num<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
