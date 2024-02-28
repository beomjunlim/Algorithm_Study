#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t>0){
        int answer = -1;
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        int max_cnt = lcm(m,n);

        for(int i=x; i<=max_cnt; i+=m){
            int tmp = i%n;
            if(tmp==0)
                tmp = n;
                
            if(tmp==y){
                answer = i;
                break;
            }
        }
        cout<<answer<<'\n';
        t--;
    }
}

