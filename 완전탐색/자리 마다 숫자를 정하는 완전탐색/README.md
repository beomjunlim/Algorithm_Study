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
https://inha.codetree.ai/missions/5/problems/ability-of-developer-3/submissions
# 풀이
총 합을 따로 구하고 경우에 따라 하나씩 계산해보면 된다.
# 코드
```
#include <iostream>
#include <climits>
using namespace std;

int arr[6];

int GetDiff(int i,int j,int k){
    int sum1 = arr[i]+arr[j]+arr[k];
    int sum2=0;
    int sum3=0;
    for(int m=0; m<6; m++){
        sum3+=arr[m];
    }
    sum2 = sum3-sum1;
    return abs(sum2-sum1);
}

int main() {
    int n=6;
    int min=0;
    int Min_min=INT_MAX;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                min = GetDiff(i,j,k);
                if(Min_min> min)
                    Min_min = min;
            }
        }
    }
    cout<<Min_min<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/a-two-way-lock/submissions
# 풀이
각 자리수 차이를 계산하는 함수를 만든다.  n을 초과할 경우 1로 다시 돌아가므로 이 경우는 두 수의 차를 이용해서 계산한다.
# 코드
```
#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr1[3];
int arr2[3];

bool GetCase(int i, int j, int k, int arr[]){
    int a=abs(arr[0]-i);
    int b=abs(arr[1]-j);
    int c=abs(arr[2]-k);
    if(a<=2||a>=(n-2)){
        if(b<=2||b>=(n-2)){
            if(c<=2||c>=(n-2))
                return true;
            return false;
        }
        return false;
    }
    return false;
}


int main() {
    cin>>n;
    for(int i=0; i<3; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<3; i++){
        cin>>arr2[i];
    }
    int sum=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(GetCase(i,j,k,arr1)||GetCase(i,j,k,arr2))
                    sum+=1;
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
