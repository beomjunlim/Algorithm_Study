#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(int argc, char** argv)
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 1;
    int End = v[0].second;
    
    for(int i=1; i<n; i++){
        if(v[i].first>=End){
            ans++;
            End = v[i].second;
        }    
    }

    cout<<ans;
   return 0;
}
