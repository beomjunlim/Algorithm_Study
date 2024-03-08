#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 500000
int card[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n;

    map<int,int> num;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[a]++;
    }

    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(num.find(a)!=num.end())
            cout<<num[a]<<" ";
        else
            cout<<0<<" ";
    }
}

