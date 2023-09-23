#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int>v;

void Print(){
    for(int i=0; i<m; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==m){
        Print();
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(v.empty()||v.back()<i){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>n>>m;
    Check(0);
    return 0;
}
