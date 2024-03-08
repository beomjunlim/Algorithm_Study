#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> stk;
    string s;
    getline(cin,s);
    
    int cnt = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(')
            stk.push(s[i]);
        else if(s[i]==')'&&s[i-1]=='('){
            stk.pop();
            cnt += stk.size();
        }
        else if(s[i]==')'){
            stk.pop();
            cnt +=1;
        }
    }

    cout<<cnt<<'\n';
}
