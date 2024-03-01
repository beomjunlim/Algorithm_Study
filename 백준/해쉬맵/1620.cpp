#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    unordered_map<int, string> name;
    unordered_map<string, int> num;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        name[i] = s;
        num[s] = i;
    }

    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(isdigit(s[0]))
            cout<<name[stoi(s)]<<'\n';
        else
            cout<<num[s]<<'\n';
    }
}

