#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    set<int> cctv;
    cctv.insert(routes[0][1]);
    answer++;
    
    for(int i=1; i<routes.size(); i++){
        auto it = cctv.lower_bound(routes[i][0]);
        if(it!=cctv.end()&&*it<=routes[i][1])
            continue;
        cctv.insert(routes[i][1]);
        answer++;
    }
    
    return answer;
}
