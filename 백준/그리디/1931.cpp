#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 1;
    cin>>n;
    vector<pair<int,int>> meeting;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        meeting.push_back({a,b});
    }

    sort(meeting.begin(), meeting.end(), cmp);

    int end = meeting[0].second;

    for(int i=1; i<n; i++){
        if(end <= meeting[i].first){
            answer++;
            end = meeting[i].second;
        }
    }

    cout<<answer<<'\n';
}

