# 문제
https://inha.codetree.ai/missions/2/problems/fibonacci-number/introduction
# 풀이
DP를 탑 다운 방식과 다운 탑 방식으로 두 가지 방법을 이용해서 구현했다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 46

int dp[MAX];
int memo[MAX];

int fibo(int n){
    if(n<=2)
        return 1;

    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibo2(int n){
    if(memo[n] != 0)
        return memo[n];
    if(n<=2)
        memo[n] = 1;
    else
        memo[n] = fibo2(n-1) + fibo2(n-2);
    return memo[n];
}

int main() {
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    cout<<fibo2(n);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/climbing-stairs/submissions
# 풀이
계단을 오르는 방식으로 DP 계산방법을 바꿔준다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 1001

int dp[MAX];

int main() {
    int n;
    cin>>n;
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<=n; i++){
        dp[i]=(dp[i-2]+dp[i-3])%10007;
    }
    cout<<dp[n];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/rectangle-fill/submissions
# 풀이
규칙을 이용해서 점화식을 찾아냈다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 1001
int dp[MAX];

int main() {
    int n;
    cin>>n;

    dp[1]=0;
    dp[2]=2;
    dp[3]=3;

    for(int i=4; i<=n; i++){
        dp[i] = (dp[i-2]+dp[i-1])%10007;
    }
    cout<<dp[n];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/rectangle-fill-3/submissions
# 풀이
데이터 타입과, 예외의 경우를 생각해서 계산해주어야 한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 1000


long long dp[MAX];

int main() {
    int n;
    cin>>n;
    
    dp[0]=1;
    dp[1]=2;
    dp[2]=7;

    for(int i=3; i<=n; i++){
        dp[i]=(2*dp[i-1]+3*dp[i-2])%1000000007;
        for(int j= i-3; j>=0; j--){
            dp[i] = (dp[i] + dp[j]*2)%1000000007;
        }
    }
    cout<<dp[n];
    return 0;
}
```
