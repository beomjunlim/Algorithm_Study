# 문제
https://inha.codetree.ai/missions/5/problems/one-way-lock/submissions
# 풀이
열리지 않는 경우를 제외하는 경우를 계산한다.  pow라는 거듭 제곱 함수를 사용한다.
# 코드
```
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int a,b,c;
    int sum;
    cin>>n>>a>>b>>c;

    sum=pow(n,3);

    for(int i=1; i<=n; i++){
        if(abs(a-i)>2){
             for(int j=1; j<=n; j++){
                if(abs(b-j)>2){
                    for(int k=1; k<=n; k++){
                        if(abs(c-k)>2)
                            sum-=1;
                    }
                }
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}
```

# 문제

# 풀이

# 코드
```

```
