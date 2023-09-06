# 문제
https://inha.codetree.ai/missions/5/problems/max-sum-of-subarray/submissions
# 풀이
구간의 범위를 잘 생각해서 풀어야 한다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];

int main() {
    int n,k;
    int max_num=0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<=n-k; i++){
        int num=0;
        for(int j=i; j<i+k; j++){
            num+=arr[j];
        }
        if(max_num<num)
            max_num = num;
    }
    cout<<max_num<<'\n';
    return 0;
}
```

# 문제

# 풀이

# 코드
```

```
