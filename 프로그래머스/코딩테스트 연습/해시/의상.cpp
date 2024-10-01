#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> wear;
    
    for(int i=0; i<clothes.size(); i++){
        string str = clothes[i][1];
        wear[str]++;
    }
    
    for(auto it : wear){
        answer *= (it.second+1);
    }
    
    answer--;
    return answer;
}
