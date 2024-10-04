#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int dist[20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> graph[n+1];
    
    for(int i=0; i<edge.size(); i++){
        int A = edge[i][0];
        int B = edge[i][1];
        
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }
    
    dist[1] = 0;
    
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,1));
    visited[1] = true;
    
    while(!pq.empty()){
        int dis = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node]<dis)
            continue;
        
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            int next_dist = dis + 1;
            
            if(dist[next]>next_dist&&!visited[next]){
                visited[next] = true;
                dist[next] = next_dist;
                pq.push(make_pair(-next_dist,next));
            }
        }
    }
    
    sort(dist+1, dist+n+1);
    answer = 1;
    
    for(int i=n-1; i>0; i--){
        if(dist[i]==dist[n])
            answer++;
    }

    
    return answer;
}
