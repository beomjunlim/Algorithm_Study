#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left_x = 3, left_y = 0, right_x = 3, right_y = 2;
    
    for(int i=0; i<numbers.size(); i++){
        int num = numbers[i];
        
        if(num==1||num==4||num==7){
            answer += "L";
            if(num==1)
                left_x = 0;
            else if(num==4)
                left_x = 1;
            else if(num==7)
                left_x = 2;
            left_y = 0;
        }
        
        else if(num==3||num==6||num==9){
            answer += "R";
            if(num==3)
                right_x = 0;
            else if(num==6)
                right_x = 1;
            else if(num==9)
                right_x = 2;
            right_y = 2;
        }
        
        else{
            int x;
            int y = 1;
            
            if(num==2)
                x = 0;
            else if(num==5)
                x = 1;
            else if(num==8)
                x = 2;
            else if(num==0)
                x = 3;
            
            int L = abs(x-left_x) + abs(y-left_y);
            int R = abs(x-right_x) + abs(y-right_y);

            if(L==R){
                if(hand=="right"){
                    answer += "R";
                    right_x = x;
                    right_y = y;
                }
                else if(hand=="left"){
                    answer += "L";
                    left_x = x;
                    left_y = y;
                }
            }
            else if(L<R){
                answer += "L";
                left_x = x;
                left_y = y;
            }
            else if(R<L){
                answer += "R";
                right_x = x;
                right_y = y;
            }
        }
    }
    return answer;
}
