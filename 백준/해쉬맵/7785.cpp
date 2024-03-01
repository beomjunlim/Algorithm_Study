#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    set<string> employee;
    vector<string> answer;

    for(int i=0; i<n; i++){
        string name, log;
        cin>>name>>log;
        if(log=="enter") employee.insert(name);
        if(log=="leave") employee.erase(name);
    }

    for(auto &it : employee){
        answer.push_back(it);
    }

    for(int i=answer.size()-1; i>=0; i--){
        cout<<answer[i]<<'\n';
    }
}

