#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s;
    cin>>s;

    long long sum = 0;
    int num = 1;
    int cnt = 0;
    while(1){
        sum += num;
        cnt++;

        if(sum>s){
            cnt--;
            break;
        }
        num++;
    }
    cout<<cnt;
}
