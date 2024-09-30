#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = length - 1;  

    for (int i = 0; i < length; i++) {
        int num = name[i] - 'A';
        answer += min(num, 26 - num);
        
        int next = i + 1;
        while (next < length && name[next] == 'A') {
            next++;
        }

        move = min(move, i + length - next + min(i, length - next));
    }
    

    answer += move;  
    return answer;
}
