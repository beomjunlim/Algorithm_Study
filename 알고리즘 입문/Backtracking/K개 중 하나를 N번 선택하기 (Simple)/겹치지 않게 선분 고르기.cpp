#include <iostream>
#include <vector>
using namespace std;

int n;
int ans=0;
vector<pair<int, int>>v;
vector<pair<int, int>>w;

bool Overlapped(pair<int, int>a, pair<int, int>b){
    int ax=a.first;
    int ay=a.second;
    int bx=b.first;
    int by=b.second;

    return (ay<bx||by<ax);
}

bool Possible(){
    for(int i=0; i<(int)w.size(); i++){
        for(int j=i+1; j<(int)w.size(); j++){
            if(!Overlapped(w[i], w[j]))
                return false;
        }
    }
    return true;
}

void Check(int num){
    if(num==n){
        if(Possible())
            ans = max(ans,(int)w.size());
        return;
    }
    w.push_back({v[num].first,v[num].second});
    Check(num+1);
    w.pop_back();
    Check(num+1);
}

int main() {

    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    Check(0);
    cout<<ans;
    return 0;
}
