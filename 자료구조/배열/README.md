# 문제
https://inha.codetree.ai/missions/6/problems/process-numeric-commands-5/description
# 풀이
먼저 명령어를 입력받고, 명령어에 따라 기능을 수행한다.
# 코드
```
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 10001

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
```
