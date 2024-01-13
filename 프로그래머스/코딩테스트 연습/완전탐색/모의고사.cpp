// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int p_one[] = {1, 2, 3, 4, 5};
int p_two[] = {2, 1, 2, 3, 2, 4, 2, 5};
int p_thr[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int one_size = 5;
int two_size = 8;
int thr_size = 10;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one_ans = 0;
    int two_ans = 0;
    int thr_ans = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(p_one[i%one_size]==answers[i])
            one_ans++;
        if(p_two[i%two_size]==answers[i])
            two_ans++;
        if(p_thr[i%thr_size]==answers[i])
            thr_ans++;
    }
    
    int max_num = 0;
    max_num = max(one_ans, max(two_ans, thr_ans));
    
    if(max_num==one_ans)
        answer.push_back(1);
    if(max_num==two_ans)
        answer.push_back(2);
    if(max_num==thr_ans)
        answer.push_back(3);
    
    return answer;
}
