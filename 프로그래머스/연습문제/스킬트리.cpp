#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> q;
    set<char> s;
    for(int i=0; i<skill.length(); i++){
        q.push(skill[i]);
        s.insert(skill[i]);
    }
    
    for(int i=0; i<skill_trees.size(); i++){
        queue<char> copy_q = q;
        bool sw = true;
        for(int j=0; j<skill_trees[i].size(); j++){
            char word = skill_trees[i][j];
            
            if(s.find(word)==s.end())
                continue;
            
            if(copy_q.front()==word){
                copy_q.pop();
            }
            else{
                sw = false;
                break;
            }
        }
        if(sw)
            answer++;
    }
    return answer;
}
