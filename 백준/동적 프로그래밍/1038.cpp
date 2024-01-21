#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX 10000010
long long dp[MAX];
int n;

void myFunction(){
    queue<long long> q;

    for(int i=1; i<=9; i++){
        q.push(i);
        dp[i] = i;
    }

    if(n<=10){
        cout<<n<<'\n';
        return;
    }

    int index = 10;

    while(index<=n&&!q.empty()){
        long long num = q.front();
        q.pop();

        int last = num%10;
        for(int i=0; i<last; i++){
            q.push(num*10 + i);
            dp[index] = num*10 + i;
            index++;
        }
    }
    if(dp[n]!=0)
        cout<<dp[n]<<'\n';
    else
        cout<<-1<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    myFunction();
  
}
