#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;
char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
char arr[5];
int idx = 1;

void backtracking(int cnt, int n){
    if(cnt==n){
        string str = "";
        for(int i=0; i<n; i++){
            str += arr[i];
        }
        
        words.push_back(str);
        return;
    }
    
    for(int i=0; i<5; i++){
        arr[cnt] = alphabet[i];
        backtracking(cnt+1,n);
    }
}

int solution(string word) {
    int answer = 0;
    for(int i=1; i<=5; i++){
        backtracking(0,i);
    }
    
    sort(words.begin(), words.end());
    
    for(int i=0; i<words.size(); i++){
        if(word==words[i]){
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}
