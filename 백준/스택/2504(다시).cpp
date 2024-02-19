#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    getline(cin,s);

    stack<char> str;

    int pro = 1;
    int sum = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            str.push(s[i]);
            pro *= 2;
        }
        else if(s[i]=='['){
            str.push(s[i]);
            pro *= 3;
        }
        else if(s[i]==')'){
            if(str.empty()||str.top()!='('){
                sum = 0;
                break;
            }
            if(s[i-1]=='('){
                sum += pro;
                pro /= 2;
                str.pop();
            }
            else{
                pro /= 2;
                str.pop();
            }
        }
        else if(s[i]==']'){
            if(str.empty()||str.top()!='['){
                sum = 0;
                break;
            }
            if(s[i-1]=='['){
                sum += pro;
                pro /= 3;
                str.pop();
            }
            else{
                pro /= 3;
                str.pop();
            }
        }
    }

    if(!str.empty())
        sum = 0;
    
    cout<<sum<<'\n';
}
