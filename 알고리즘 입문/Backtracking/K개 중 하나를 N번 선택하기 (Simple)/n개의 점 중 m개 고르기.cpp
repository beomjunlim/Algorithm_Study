#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

#define MAX 20

vector<pair<int,int>>v;
vector<pair<int,int>>w;
bool visited[MAX];
double ans = 10000000;
int n,m;

double Dist(){
    double dist_max = 0;
    for(int i=0; i<m; i++){
        int x1 = w[i].first;
        int y1 = w[i].second;
        for(int j=i+1; j<m; j++){
            int x2 = w[j].first;
            int y2 = w[j].second;
            dist_max = max(pow(x2-x1,2)+pow(y2-y1,2),dist_max);
        }
    }
    return dist_max;
}

void Check(int num, int start){
    if(num==m){
        ans = min(ans, Dist());
        return;
    }

    for(int i=start; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            w.push_back({v[i].first, v[i].second});
            Check(num+1, i+1);
            visited[i]=false;
            w.pop_back();
        }
    }
}

int main() {

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    Check(0,0);
    cout<<ans;

    return 0;
}
