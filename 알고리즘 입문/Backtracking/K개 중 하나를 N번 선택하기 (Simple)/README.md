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
