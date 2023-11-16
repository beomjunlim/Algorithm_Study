#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> arr;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        char a;
        cin>>a;
        arr.push_back(a);
    }

    list<char>::iterator it;

    it=arr.end();
    for(int i=0; i<m; i++){
        char cmd;
        cin>>cmd;
        if(cmd == 'L'){
            if(it==arr.begin())
                continue;
            else
                it--;
        }
        if(cmd == 'R'){
            if(it==arr.end())
                continue;
            else
                it++;
        }
        if(cmd =='D'){
            if(it == arr.end())
                continue;
            else{
                it = arr.erase(it);
            }
                
        }
        if(cmd =='P'){
            char b;
            cin>>b;
            arr.insert(it, b);
        }
    }

    for(it = arr.begin(); it != arr.end(); it++)
        cout<<*it;
    return 0;
}
