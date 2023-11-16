#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cin>>n;
    list<int> arr;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s == "push_front"){
            int n;
            cin>>n;
            arr.push_front(n);
        }
        if(s == "push_back"){
            int n;
            cin>>n;
            arr.push_back(n);
        }
        if(s == "pop_back"){
            cout<<arr.back()<<'\n';
            arr.pop_back();
        }
        if(s == "pop_front"){
            cout<<arr.front()<<'\n';
            arr.pop_front();
        }
        if(s == "size"){
            cout<<arr.size()<<'\n';
        }
        if(s == "empty"){
            cout<<arr.empty()<<'\n';
        }
        if(s == "front"){
            cout<<arr.front()<<'\n';
        }
        if(s == "back"){
            cout<<arr.back()<<'\n';
        }
    }
    return 0;
}
