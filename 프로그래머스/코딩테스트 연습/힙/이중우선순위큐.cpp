// https://school.programmers.co.kr/learn/courses/30/lessons/42628?language=cpp#
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> arr;
    
    for(int i=0; i<operations.size(); i++){
        if(operations[i].substr(0, operations[i].find(" "))=="I"){
            int num = stoi(operations[i].substr(operations[i].find(" ")+1, operations[i].length()));
            arr.insert(num);
        }
        else{
            if(arr.empty())
                continue;
            else if(operations[i].substr(operations[i].find(" ")+1, operations[i].length())=="1"){
               auto it = arr.find(*prev(arr.end()));
                arr.erase(it);
            }
            else{
               auto it = arr.find(*arr.begin());
                arr.erase(it);
            }
        }
    }
    
    if(arr.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*prev(arr.end()));
        answer.push_back(*arr.begin());
    }

    return answer;
}
