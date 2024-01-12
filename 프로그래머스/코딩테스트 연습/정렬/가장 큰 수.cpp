// https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i=0; i<numbers.size(); i++){
        str.push_back(to_string(numbers[i]));  
    }
    
    sort(str.begin(), str.end(), compare);
    
    for(int i = 0; i<str.size(); i++){
        if(str[0] == "0"){
            answer = "0";
            break;
        }
        answer += str[i];
    }
    return answer;
}
