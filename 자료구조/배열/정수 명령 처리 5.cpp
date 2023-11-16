#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int>arr;
    cin>>n;

    for(int i=0; i<n; i++){
        string cmd;
        cin>>cmd;
        if(cmd=="push_back"){
            int num;
            cin>>num;
            arr.push_back(num);
        }
        if(cmd=="pop_back"){
            arr.pop_back();
        }
        if(cmd=="get"){
            int num;
            cin>>num;
            cout<<arr[num-1]<<'\n';
        }
        if(cmd=="size"){
            cout<<arr.size()<<'\n';
        }
    }
    return 0;
}
