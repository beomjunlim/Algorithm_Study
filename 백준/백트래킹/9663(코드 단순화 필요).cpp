#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 15
int n;
int cnt = 0;
int arr[MAX][MAX];

bool check(int a, int k){
    for(int i=0; i<n; i++){
        if(arr[a][i]==1&&i!=k)
            return false;
        if(arr[i][k]==1&&i!=a)
            return false;
    }

    if(a>k){
        for(int i=a-k; i<n; i++){
            if(i!=a&&i-a+k!=k&&arr[i][i-a+k]==1)
                return false;
        }
    }

    else{
        for(int i= k-a; i<n; i++){
            if(i!=k&&i-k+a!=a&&arr[i-k+a][i]==1)
                return false;
        }
    }

    for(int i=n-1; i>=a+k-n; i--){
        int x = i;
        int y = a+k-i;
        if(0<=x&&x<n&&0<=y&&y<n){
            if(x!=a&&y!=k&&arr[x][y]==1)
                return false;
        }
    }
    return true;
}

void func(int a){
    if(a==n){
        cnt++;
    }

    else{
        for(int i=0; i<n; i++){
            arr[a][i] = 1;
            if(check(a, i)){
                func(a+1);
            }
            arr[a][i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    func(0);
    cout<<cnt;

}


