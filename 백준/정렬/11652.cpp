#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    map<long long,int> num;

    for(int i=0; i<n; i++){
        long long a;
        cin>>a;
        num[a]++;    
    }

    long long answer = 0;
    int max_num = 0;
    for(auto &it : num){
        if(max_num<it.second){
            max_num = it.second;
            answer = it.first;
        }
        else if(max_num==it.second)
            answer = min(answer, it.first);
    }

    cout<<answer<<'\n';

}

