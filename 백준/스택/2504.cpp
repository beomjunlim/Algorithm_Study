#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<climits>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    stack<char> str;
    
    int answer = 0;
    int tmp = 1;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            str.push(s[i]);
            tmp *= 2;
        }

        else if(s[i]=='['){
            str.push(s[i]);
            tmp *= 3;
        }

        else if(s[i]==')'){
            if(str.empty()||str.top()!='('){
                answer = 0;
                break;
            }
            if(s[i-1]=='('){
                answer += tmp;
                tmp /= 2;
                str.pop();
            }
            else{
                tmp /= 2;
                str.pop();
            }
        }
        else if(s[i]==']'){
            if(str.empty()||str.top()!='['){
                answer = 0;
                break;
            }
            if(s[i-1]=='['){
                answer += tmp;
                tmp /= 3;
                str.pop();
            }
            else{
                tmp /= 3;
                str.pop();
            }
        }
    }

    if(!str.empty())
        answer = 0;

    cout<<answer;
}
