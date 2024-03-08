#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int answer = 0;

    for(int i=1; i<=n; i*=10){
        answer += n-i+1;
    }
    
    cout<<answer<<'\n';
}
