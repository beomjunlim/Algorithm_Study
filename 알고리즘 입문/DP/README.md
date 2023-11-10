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

# 문제
https://inha.codetree.ai/missions/2/problems/minimax-path-in-square/explanation
# 풀이
먼저 초기 조건을 만드는 함수를 만들어주고, 이동할 수 있는 경우의 수 중 작은 경우와 이동한 칸의 수와 비교해서 큰 값으로 dp 배열을 채워나간다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 100

int dp[MAX][MAX];
int arr[MAX][MAX];
int n;

void Initialize(){
    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        dp[0][i] = max(dp[0][i-1],arr[0][i]);
    }

    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], arr[i][0]);
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
        for(int j=1; j<n; j++){
            dp[i][j] = max(min(dp[i-1][j],dp[i][j-1]), arr[i][j]);
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/longest-increasing-subsequence/submissions
# 풀이
도착점을 기준으로 이전에 왔던 지점과 크기를 비교해가며 이전 지점까지의 수열과 계산한다.
# 코드
```
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 1000

int arr[MAX+1];
int dp[MAX+1];
int n;

void Initialize(){
    for(int i=0; i<=n; i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    arr[0] = 0;
}

int main() {

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    Initialize();
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans=0;

    for(int i=0; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans;

    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/longest-decreasing-subsequence/submissions
# 풀이
도착 지점까지 감소하는 수열을 하나씩 비교하면 채워나간다.
# 코드
```
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int n;
int arr[MAX];
int dp[MAX];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/maximum-number-of-jumps/submissions
# 풀이
조건이 시작지점에서 점프를 해야 하므로 도달할 수 없는 지점은 계산에서 제외시키는 if문을 추가해준다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 1000

int arr[MAX];
int dp[MAX];
int n;

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(dp[j] == INT_MIN)
                continue;
            if(arr[j]>=i-j){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    int ans = 0 ;

    for(int i=0; i<n; i++){
        ans = max (ans, dp[i]);
    }

    cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/longest-increasing-sequence-2d/submissions
# 풀이
2차원 배열이므로 for문을 이용해서 점프한 지점에서 그 전 지점과 비교해가며서 점프할 수 있는 지점인지, 최대 점프 횟수를 갱신한다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 50
int n,m;
int arr[MAX][MAX];
int dp[MAX][MAX];


int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<i; k++){
                for(int l=0; l<j; l++){
                    if(dp[k][l] == INT_MIN)
                        continue;
                    
                    if(arr[k][l]<arr[i][j])
                        dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            ans = max(ans, dp[i][j]);
    }

    cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/select-segments-without-overlap-2/explanation
# 풀이
다음 지점의 첫번째 시작과 비교하는 지점의 끝 지점을 비교하며 dp 배열을 갱신시켜준다.
# 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int n;
vector<pair<int,int>> v;
int dp[MAX];

bool my_asc(pair<int, int>v, pair<int, int>w){
    return v.second<w.second;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    dp[0] = 1;

    sort(v.begin(), v.end(),my_asc);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[j].second<v[i].first){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    
    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/being-rich-by-working-part-time/explanation
# 풀이
입력 순서가 정해져있으므로 비용은 따로 빼줘서 계산을 진행하면 된다.
# 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000
int n;
vector<pair<int,int>> v;
vector<int> pay;
int dp[MAX];

int main() {
    cin>>n;
    
    for(int i=0; i<n; i++){
        int s,e,p;
        cin>>s>>e>>p;
        v.push_back(make_pair(s,e));
        pay.push_back(p);
        dp[i] = p;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i].first>v[j].second){
                dp[i] = max(dp[i], dp[j]+pay[i]);
            }
        }
    }
    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/coin-change/submissions
# 풀이
금액과 동정 사용하는 것을 기준으로 하나식 채워나간다.
# 코드
```
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 10001
int n,m;
int coin[MAX];
int dp[MAX];

int main() {
    cin>>n>>m;

    coin[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }

    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(coin[j]<=i){
                if(dp[i-coin[j]]==INT_MAX)
                    continue;
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }

    int ans = dp[m];
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/1-2-5-plus/submissions
# 풀이
먼저 자기 자신으로 만들 수 있는 수를 초기화 시켜주고 dp 배열을 업데이트 시켜준다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 1000

int arr[3] = {1,2,5};
int n;
int dp[MAX];

int main() {
    cin>>n;
    dp[1] = 1;
    dp[2] = 1;
    dp[5] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(i>arr[j])
                dp[i] = (dp[i] + dp[i-arr[j]])%10007;
        }
    }
    cout<<dp[n];
    
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/max-coin-change/explanation
# 풀이
도달할 수 없는 지점의 경우 그냥 건너뛰면서 dp 배열을 업데이트한다.
# 코드
```
#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001
int n,m;
int arr[MAX];
int dp[MAX];

void Initialize() {
    for(int i=1; i<=m; i++){
        dp[i] = INT_MIN;
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Initialize();
    dp[0] = 0;
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i>=arr[j]){
                if(dp[i - arr[j]] == INT_MIN)
                    continue;
                dp[i] = max (dp[i], dp[i-arr[j]] + 1);
            }
        }
    }

    if(dp[m] == INT_MIN)
        cout<<-1;
    else
        cout<<dp[m];


    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/the-sum-of-the-subsequences/submissions
# 풀이
배열의 인덱스까지 해당 숫자를 만들 수 있는지 bool 형 배열을 생성하여 확인한다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 10001

int n,m;
int arr[MAX];
bool dp[MAX][MAX];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j >=arr[i] && dp[i -1][j -arr[i]])
                dp[i][j] = true;
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }
    if(dp[n][m])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/knapsack/submissions
# 풀이
물건의 번호를 두고 해당 물건까지 포함했을 경우 무게를 업데이트하며 가능한 최대의 가치를 업데이트한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 10001
int n, m;
int value[MAX];
int weight[MAX];
int dp[MAX][MAX];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        cin >> value[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j>=weight[i])
                dp[i][j] = max(dp[i-1][j - weight[i]] + value[i], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int ans =0;

    for(int i=0; i<=m; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans;
    return 0;
}

```

# 문제
https://inha.codetree.ai/missions/2/problems/rod-cutting/explanation
# 풀이
길이에따라서 하나씩 비교하며 최대 이윤을 갱신해준다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 10001
int n;
int arr[MAX];
int dp[MAX];

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[0] = 0;

    for(int i=1; i<=n; i++){
        dp[i] = arr[i];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }
    
    cout<<dp[n];
    return 0;
}
```


# 문제
https://inha.codetree.ai/missions/2/problems/knapsack-2/submissions
# 풀이
보석을 중복 가능하게 고를 수 있으므로 보석을 첫번째 for문으로 가서 해당 번호 보석까지 고를 수 있을 때 무게를 업데이트하며 dp 배열을 갱신한다.
# 코드
```
#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001

int n,m;
int weight[MAX];
int value[MAX];
int dp[MAX][MAX];

void Initialize() {
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = 0;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }

    Initialize();
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j>=weight[i]){
                dp[i][j] = max (dp[i-1][j], dp[i][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}
```
