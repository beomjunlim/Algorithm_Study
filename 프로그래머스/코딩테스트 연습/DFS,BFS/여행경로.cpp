#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> answer;
map<string, int> city;
vector<pair<string,int>> airport[10001];
bool visited[10001];

void dfs(int num, int ticket){
    if(answer.size()==ticket+1)
        return;
    
    for(int i=0; i<airport[num].size(); i++){
        string next = airport[num][i].first;
        int idx = airport[num][i].second;
        
        if(!visited[idx]){
            visited[idx] = true;
            answer.push_back(next);
            dfs(city[next], ticket);
            
            if(answer.size()==ticket+1)
                return;
            
            visited[idx] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int idx = 0;
    for(int i=0; i<tickets.size(); i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        
        if(city.find(start)==city.end()){
            city[start] = idx;
            idx++;
        }
        
        if(city.find(end)==city.end()){
            city[end] = idx;
            idx++;
        }
    }
    
    for(int i=0; i<tickets.size(); i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        
        airport[city[start]].push_back(make_pair(end,i));
    }
    
    for(int i=0; i<idx; i++){
        sort(airport[i].begin(), airport[i].end());
    }
    
    answer.push_back("ICN");
    dfs(city["ICN"], tickets.size());
    return answer;
}
