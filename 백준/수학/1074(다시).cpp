#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int func(int x, int y, int n){
    if(n==0) return 0;
    
    int size = pow(2,n)/2;

    if(x<size && y<size) return func(x,y, n-1);
    if(x<size && y>=size) return pow(size,2) + func(x, y-size, n-1);
    if(x>=size && y<size) return 2*pow(size,2) + func(x-size, y, n-1);
    return 3*pow(size,2) + func(x-size, y-size, n-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin>>n>>r>>c;
    cout<<func(r,c,n);
}
