#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 9
int n,m;
vector<int> v;
bool visited[MAX];

void func(int a){
    if(a==m){
        for(int i=0; i<m; i++){
            cout<<v[i]<<" ";
        }
        cout<<'\n';
    }
    else{
        for(int i=1; i<=n; i++){
            if(!visited[i]){
            v.push_back(i);
            visited[i] = true;
            func(a+1);
            v.pop_back();
            visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;
    func(0);
}
