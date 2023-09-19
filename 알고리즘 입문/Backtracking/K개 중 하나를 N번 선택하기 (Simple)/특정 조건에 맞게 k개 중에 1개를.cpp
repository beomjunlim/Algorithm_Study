#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void Print() {
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        Print();
        return;
    }

    for(int i=1; i<=k; i++){
        if(v.size()>=2&&i==v[num-1]&&i==v[num-2]){
            continue;
        } else{
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>k>>n;
    Check(0);
    return 0;
}
