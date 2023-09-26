#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

vector<int> v;
bool visited[MAX];
int n;

void Print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Chechk(int num){
    if(num==n)
        Print();
    
    for(int i=n; i>0; i--){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            Chechk(num+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    cin>>n;
    Chechk(0);
    return 0;
}
