#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

#define MAX 21
int n;
int ans = INT_MAX;
int arr[MAX][MAX];
bool num[MAX];

void check(){
    int one = 0;
    int two = 0;
    for(int i=1; i<=n; i++){

    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(num[i]&&num[j])
                one += arr[i][j];
            else if(!num[i]&&!num[j])
                two += arr[i][j];
        }
    }
    ans = min(ans, abs(one-two));
}

void myfunction(int cnt, int idx){
    if(cnt==n/2){
        check();
    }

    for(int i=idx; i<=n; i++){
        num[i] = true;
        myfunction(cnt+1, i+1);
        num[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    myfunction(0,1);
    cout<<ans<<'\n';
}

