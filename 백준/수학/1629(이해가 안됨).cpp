#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long A, B, C;

long long pro(long long b){
    if(b==0) return 1;
    if(b==1) return A%C;

    long long tmp = pro(b/2)%C;
    if(b%2==0) return tmp*tmp%C;
    else return (tmp*tmp%C)*(A%C);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>A>>B>>C;
    cout<<pro(B)%C;

}
