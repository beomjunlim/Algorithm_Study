#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 20
int n, s;
int cnt = 0;
int arr[MAX];
bool visited[MAX];

void func(int a, int sum){
    if(a!=0&&sum==s){
        cnt++;
    }
    
    for(int i=a; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            sum += arr[i];
            func(i+1, sum);
            visited[i] = false;
            sum -= arr[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>s;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    func(0,0);
    cout<<cnt<<'\n';
}


