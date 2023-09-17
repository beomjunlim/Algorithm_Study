# 문제
https://inha.codetree.ai/missions/2/problems/n-permutations-of-k-with-repetition/introduction
# 풀이
길이를 종료조건으로 두고 for문을 이용해 순서대로 하나씩 넣어보며 출력한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> v;

void print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        print();
        return;
    }
    else{
        for(int i=1; i<=k; i++){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>k>>n;
    Check(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/beautiful-number/submissions
# 풀이
백트래킹을 이용해서 경우를 하나씩 살펴보면서 아름다운 수를 확인해본다.  
배열 안의 숫자를 비교해가면서 아름다운 수를 확인한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
vector<int> v;
int n;
int res=0;

bool BtfNum(){
    int cnt=0;
    int i=0;
    while(i!=n){
        int k=v[i];
        cnt=1;
        while(k!=cnt){
            i++;
            if(i==n||k!=v[i])
                return false;
            cnt++;
        }
        i++;
    }
    return true;
}

void Check(int num){
    if(num==n){
        if(BtfNum())
            res++;
        return;
    }
    else{
        for(int i=1; i<=4; i++){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>n;
    Check(0);
    cout<<res<<'\n';
    return 0;
}
```
