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

# 문제
https://inha.codetree.ai/missions/6/problems/process-numeric-commands-8/submissions
# 풀이
리스트가 어떻게 활용되는지 본다.
# 코드
```
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
```

# 문제
https://inha.codetree.ai/missions/6/problems/golden-toast/submissions
# 풀이
iterator의 사용법을 이용한다.
# 코드
```
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
```
