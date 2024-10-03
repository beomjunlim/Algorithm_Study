#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include<iostream>
using namespace std;

bool visited[101];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,int> > cost[n];
    for(int i=0; i<costs.size(); i++){
        for(int j=0; j<costs[i].size(); j++){
            int A = costs[i][0];
            int B = costs[i][1];
            int dis = costs[i][2];
            cost[A].push_back(make_pair(B,dis));
            cost[B].push_back(make_pair(A,dis));
        }
    }
    
    vector<int> node;
    node.push_back(0);
    visited[0] = true;
    int island = 1;
    int idx = 0;
    while(island<n){
        int dist = INT_MAX;
        int next_idx;
        for(int i=0; i<node.size(); i++){
            int idx = node[i];
            for(int j=0; j<cost[idx].size(); j++){
                if(dist>cost[idx][j].second&&!visited[cost[idx][j].first]){
                    next_idx = cost[idx][j].first;
                    dist = cost[idx][j].second;
                }
            }
        }
        
        answer += dist;
        node.push_back(next_idx);
        visited[next_idx] = true;
        island++;
    }
    
    return answer;
}
