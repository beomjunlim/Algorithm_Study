#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        stack<char> stk;
        string s;
        bool sw = false;
        getline(cin,s);
        
        if(s==".")
            break;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='(')
                stk.push(s[i]);

            if(s[i]=='[')
                stk.push(s[i]);

            if(s[i]==')'){
                if(!stk.empty()&&stk.top()=='(')
                    stk.pop();
                else{
                    sw = true;
                    break;
                }
            }

            if(s[i]==']'){
                if(!stk.empty()&&stk.top()=='[')
                    stk.pop();
                else{
                    sw = true;
                    break;
                }
            }
        }
        
        if(!sw&&stk.empty())
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
    }
}
