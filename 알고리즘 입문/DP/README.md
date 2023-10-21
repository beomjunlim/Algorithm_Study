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

# 문제
https://inha.codetree.ai/missions/2/problems/rectangle-fill-2/submissions
# 풀이
점화식을 구해서 DP 문제를 해결했다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 1001

long long dp[MAX];

int main() {
    int n;
    cin>>n;

    dp[1]=1;
    dp[2]=3;

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1]+2*dp[i-2])%10007;
    }
    cout<<dp[n];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/maximum-sum-path-in-square/submissions
# 풀이
먼저 dp 배열의 초기를 설정하고 점화식을 이용해서 구한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int dp[MAX][MAX];
int n;

void Initialize(){
    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }

    for(int i=1; i<n; i++){
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    Initialize();

    for(int i= 1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }
    cout<<dp[n-1][n-1];


    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/minimum-sum-path-in-square/submissions
# 풀이
초기 조건을 먼저 설정해주고 움직일 수 있는 경우를 계산하며 최소값으로 채워나간다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int dp[MAX][MAX];
int n;

void Initialize(){
    dp[0][n-1] = arr[0][n-1];
    for(int i=1; i<n; i++){
        dp[i][n-1] = dp[i-1][n-1] + arr[i][n-1];
    }
    for(int i=n-2; i>=0; i--){
        dp[0][i] = dp[0][i+1] + arr[0][i];
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    Initialize();

    for(int i=1; i<n; i++){
        for(int j=n-2; j>=0; j--){
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + arr[i][j];
        }
    }

    cout<<dp[n-1][0];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/maximin-path-in-square/submissions
# 풀이
초기 설정을 해주고 움직일 때 최대값을 가지며 그 다음 값을 비교하며 채워나간다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
int n;
int dp[MAX][MAX];
int arr[MAX][MAX];

void Initialize(){
    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++)
        dp[i][0] = min(dp[i-1][0], arr[i][0]);
    
    for(int i=1; i<n; i++)
        dp[0][i] = min(dp[0][i-1], arr[0][i]);
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    Initialize();

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]),arr[i][j]);
        }
    }

    cout<<dp[n-1][n-1];
    return 0;
}
```
