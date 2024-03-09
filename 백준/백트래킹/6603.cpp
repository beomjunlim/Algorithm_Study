#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int ans[6];
int num[13];

void print(int cnt, int idx){
    if(cnt==6){
        for(int i=0; i<6; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=idx; i<n; i++){
        ans[cnt] = num[i];
        print(cnt+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){

        cin>>n;
        if(n==0) break;

        for(int i=0; i<n; i++){
            cin>>num[i];
        }

        print(0,0);
        cout<<'\n';
    }
}
