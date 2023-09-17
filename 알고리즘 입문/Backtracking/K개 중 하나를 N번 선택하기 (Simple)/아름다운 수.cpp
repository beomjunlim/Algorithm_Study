#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
vector<int> v;
int n;
int res=0;

bool BtfNum(){
    int cnt=0;
    int i=0;
    while(i!=n){
        int k=v[i];
        cnt=1;
        while(k!=cnt){
            i++;
            if(i==n||k!=v[i])
                return false;
            cnt++;
        }
        i++;
    }
    return true;
}

void Check(int num){
    if(num==n){
        if(BtfNum())
            res++;
        return;
    }
    else{
        for(int i=1; i<=4; i++){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>n;
    Check(0);
    cout<<res<<'\n';
    return 0;
}
