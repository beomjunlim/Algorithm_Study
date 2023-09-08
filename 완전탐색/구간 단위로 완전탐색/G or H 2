#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100

int main() {
    int n;
    int max_num=0;
    cin>>n;
    vector<pair<int,char>> v;
    for(int i=0; i<n; i++){
        int a;
        char s;
        cin>>a>>s;
        v.push_back({a,s});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n-1; i++){
        int cnt_h=0;
        int cnt_g=0;
        if(v[i].second=='H')
            cnt_h+=1;
        else
            cnt_g+=1;
        for(int j=i+1; j<n; j++){
            int num=0;
            if(v[j].second=='H')
                cnt_h+=1;
            else
                cnt_g+=1;
            
            if(cnt_h==cnt_g){
                num=v[j].first-v[i].first;
                if(max_num<num)
                    max_num=num;
            }
        }
    }
    cout<<max_num<<'\n';
    return 0;
}
