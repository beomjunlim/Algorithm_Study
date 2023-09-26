#include <iostream>
#include <vector>
using namespace std;

#define MAX 8
int n;
vector<int> v;
bool visited[MAX];

void Print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        Print();
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            Check(num+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin>>n;
    Check(0);
    return 0;
}
