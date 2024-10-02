#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[51];

bool canTransform(string a, string b){
    int diff = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i])
            diff++;
    }
    
    if(diff==1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool sw = false;
    for(int i=0; i<words.size(); i++){
        if(target==words[i])
            sw = true;
    }
    
    if(sw){
        queue<pair<string, int> > q;
        q.push(make_pair(begin,0));
        
        while(!q.empty()){
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            if(str==target){
                answer = cnt;
                break;
            }
            
            for(int i=0; i<words.size(); i++){
                if(!visited[i]&&canTransform(str, words[i])){
                    visited[i] = true;
                    q.push(make_pair(words[i], cnt+1));
                }
            }
        }
    }
    return answer;
}
