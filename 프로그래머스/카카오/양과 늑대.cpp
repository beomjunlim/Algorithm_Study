#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> node[18];
int answer = 0;

void dfs(vector<int> info, int cur, int sheep, int wolf, set<int> possible){
    if(info[cur]==0)
        sheep++;
    else
        wolf++;
    
    if(wolf>=sheep)
        return;
    
    answer = max(answer, sheep);
    
    set<int> next = possible;
    
    for(int n : node[cur]){
        next.insert(n);
    }
    
    for(int n : next){
        dfs(info, n, sheep, wolf, next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i=0; i<edges.size(); i++){
        int parent = edges[i][0];
        int left = edges[i][1];
        node[parent].push_back(left);
    }
    
    set<int> possible;
    for(int n : node[0]){
        possible.insert(n);
    }
    
    dfs(info, 0, 0, 0, possible);
    return answer;
}
