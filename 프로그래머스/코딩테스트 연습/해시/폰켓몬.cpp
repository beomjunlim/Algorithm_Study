// https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    int answer = 0;
    int sum = nums.size();
    for(int i=0; i<sum; i++){
        s.insert(nums[i]);
    }
    
    answer = min((int)sum/2, (int)s.size());

    return answer;
}
