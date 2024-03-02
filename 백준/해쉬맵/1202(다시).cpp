#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> jewel;
    multiset<int> bag;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        jewel.push_back({a,b});
    }

    for(int i=0; i<k; i++){
        int c;
        cin>>c;
        bag.insert(c);
    }

    sort(jewel.begin(), jewel.end(), cmp);

    long long answer = 0;

    for(int i=0; i<n; i++){
        int weight = jewel[i].first;
        int value = jewel[i].second;

        auto it = bag.lower_bound(weight);
        if(it==bag.end()) continue;
        else{
            answer += value;
            bag.erase(it);
        }
    }

    cout<<answer<<'\n';


}

