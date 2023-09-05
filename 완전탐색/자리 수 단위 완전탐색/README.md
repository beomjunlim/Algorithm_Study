# 문제
https://inha.codetree.ai/missions/5/problems/gather/explanation
# 풀이
완전탐색을 이용해서 문제를 풀었고, math.h 헤더 파일에 있는 절댓값을 나타내는 abs()함수 사용법을 알았다.  
int형의 경우 abs() long은 labs() double의 경우 fabs()를 사용한다.
# 코드
``` 
#include <iostream>
#include <math.h>
#include<climits>
using namespace std;

#define MAX 101
int arr[MAX];

int main()
{
  int n;
  int sum;
  int min_sum = INT_MAX;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++)
  {
    sum = 0;
    for (int j = 1; j <= n; j++)
    {
      sum += abs(i - j) * arr[j];
    }
    if (min_sum > sum)
      min_sum = sum;
  }
  cout << min_sum << '\n';
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/pair-parentheses-3/submissions
# 풀이
완전 탐색을 이용해서 모든 경우를 생각해본다.
# 코드
``` 
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.length(); i++)
  {
    for (int j = i + 1; j < s.length(); j++)
    {
      if (s[i] == '(' && s[j] == ')')
        cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/cattle-in-a-rowing-up-2/submissions
# 풀이
완전탐색이므로 모든 경우를 비교하고 위해 3중 for문을 이용해서 문제를 해결했다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX];

int main() {
    int n;
    int sum=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            for(int k=j+1; k<=n; k++){
                if(arr[i]<=arr[j]){
                    if(arr[j]<=arr[k])
                        sum+=1;
                }
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/best-place-of-13/submissions
# 풀이
완전탐색을 이용해서 격자를 기준으로 해서 for문 조건을 변형시켜 문제를 해결했다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 21

int arr[MAX][MAX];

int main() {
    int n;
    int max_num=0;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    int num;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-2; j++){
            num=0;
            num+=(arr[i][j]+arr[i][j+1]+arr[i][j+2]);
            if(max_num<num){
                max_num=num;
            }
        }
    }
    cout<<max_num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/on-the-checkboard-2/submissions
# 풀이
퐁당퐁당 이런식으로 진행하는데 시작과 도착 지점이 같은 색인 경우는 어떤 경우에서도 조건을 만족 못한다.  
이 경우를 생각하지 못했다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 16
char arr[MAX][MAX];

int r,c,x,y;

int CheckMove(int i, int j){
    int num=0;
    for(int a=i+1; a<r; a++){
        for(int b=j+1; b<c; b++){
            if(arr[i][j]!=arr[a][b]){
                num+=1;
            }
        }
    }
    return num;
}



int main() {
    int sum=0;
    cin>>r>>c;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>arr[i][j];
        }
    }
    x=y=1;
    for(int i=2; i<r; i++){
        for(int j=2; j<c; j++){
            if(arr[x][y]!=arr[i][j]){
                sum+=CheckMove(i,j);
            }
        }
    }
    if(arr[x][y]==arr[r][c])
        cout<<0<<'\n';
    else
        cout<<sum<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/awkward-digits-2/submissions
# 풀이
문제에서 한번은 무조건 바꿔야 한다 했다.  
따라서 모두 1인 경우에는 for문에서 바뀌는 경우가 없으므로 이를 생각해서 sw를 추가해 주었다.
# 코드
``` 
#include <iostream>
#include<cmath>
using namespace std;

int main() {
    bool sw=false;
    string a;
    int num=0;
    cin>>a;
    for(int i=0; i<a.length(); i++){
        if(a[i]=='0'){
            sw=true;
            a[i]='1';
            break;
        }
    }

    if(!sw){
        a[a.length()-1]='0';
    }
    
    for(int i=0; i<a.length(); i++){
        if(a[i]=='1'){
             num+=pow(2,a.length()-(i+1));
        }
    }
    cout<<num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/taking-a-taxi-in-the-middle-of-the-marathon-2/submissions
# 풀이
시작 도착점을 제외하고 제외할 점을 하나씩 찾고, 그 다음 지점을 x,y에 저장하며 계산한다.
# 코드
``` 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  int n, x, y;
  int sum;
  int min_sum = INT_MAX;
  cin >> n;
  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    v[i].first = a;
    v[i].second = b;
  }

  for (int i = 1; i < n - 1; i++)
  {
    x = y = 0;
    sum = 0;
    for (int j = 1; j < n; j++)
    {
      if (i != j)
      {
        sum += abs(v[x].first - v[j].first);
        sum += abs(v[y].second - v[j].second);
        x = y = j;
      }
    }
    if (min_sum > sum)
    {
      min_sum = sum;
    }
  }
  cout << min_sum << '\n';
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/a-room-in-a-circle/submissions
# 풀이
거리를 계산하는 방법을 생각하지 못했었다. 나머지를 보는 방법을 이용해서 거리를 구한다.
# 코드
``` 
#include <iostream>
#include<climits>
using namespace std;

#define MAX 1004
int arr[MAX];

int main() {
    int n;
    int min_sum=INT_MAX;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        int sum=0;
        int num=0;
        for(int j=1; j<=n; j++){
          int dist = (j+n-i)%n;
          sum+=dist*arr[j];
        }
        if(min_sum>sum){
            min_sum=sum;
        }
    }
    cout<<min_sum<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/pair-parentheses-2/submissions
# 풀이
닫는 괄호를 체크하는 함수를 이용해서 여는 괄호 두개가 연속하고 나온 후 그 다음 닫는 괄호가 두번 연속 나오는 경우를 리턴하는 함수를 만든다.
# 코드
``` 
#include <iostream>
using namespace std;

string s;

int CheckStr(int i){
    int num=0;
    for(int j=i+1; j<s.length()-1; j++){
        if(s[j]==')'){
            if(s[j+1]==')')
                num+=1;
        }
    }
    return num;
}

int main() {
    int num=0;
    cin>>s;

    for(int i=0; i<s.length()-3; i++){
        if(s[i]=='('){
            if(s[i+1]=='('){
                num+=CheckStr(i+1);
            }
        }
    }
    cout<<num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/two-non-adjacent-numbers/submissions
# 풀이
기본적인 완전 탐색을 이용하여 문제를 해결했다.
# 코드
``` 
#include <iostream>
#include<climits>
using namespace std;

#define MAX 100
int arr[MAX];

int main() {
    int n,sum;
    int max_sum=INT_MIN;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n-2; i++){
        for(int j=i+2; j<n; j++){
            sum=0;
            sum+=(arr[i]+arr[j]);
            if(max_sum<sum){
                max_sum=sum;
            }
        }
    }
    cout<<max_sum<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/c-o-w-2/submissions
# 풀이
C가 나오고 나서 O를 찾는 함수를 호출하고 O를 찾는 함수에서 W를 찾는 함수를 호출하는 식으로 완전 탐색을 진행한다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 100
char arr[MAX];
int n;

int findW(int j){
    int num=0;
    for(int k=j+1; k<n; k++){
        if(arr[k]=='W'){
            num+=1;
        }
    }
    return num;
}

int findO(int i){
    int num=0;
    for(int j=i+1; j<n-1; j++){
        if(arr[j]=='O'){
            num+=findW(j);
        }
    }
    return num;
}


int main() {

    int sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n-2; i++){
        if(arr[i]=='C'){
            sum+=findO(i);
        }
    }
    cout<<sum<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/escaping-carry-2/submissions
# 풀이
문제 조건을 보고 모든 경우를 다 계산하는 방법으로 푸는 문제이다.
# 코드
``` 
#include <iostream>
#include<climits>
using namespace std;

#define MAX 20
int arr[MAX];
bool CheckCarry(int i, int j, int k) {
    if(arr[i]%10+arr[j]%10+arr[k]%10>=10)
        return true;
    if(arr[i]%100+arr[j]%100+arr[k]%100>=100)
        return true;
    if(arr[i]%1000+arr[j]%1000+arr[k]%1000>=1000)
        return true;
    if(arr[i]%10000+arr[j]%10000+arr[k]%10000>=10000)
        return true;
    else
        return false;

}

int main() {
    int n;
    int max_sum=INT_MIN;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n-2; i++){
        
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int sum=0;
                if(!CheckCarry(i,j,k)){
                    sum+=arr[i]+arr[j]+arr[k];
                    if(max_sum<sum){
                        max_sum=sum;
                    }
                }
            }
        }
    }
    if(max_sum==INT_MIN){
        cout<<-1<<'\n';
    }
    else {
        cout<<max_sum<<'\n';
    }
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/O-mok/submissions
# 풀이
첫번째 기준으로 오른쪽 왼쪽대각선 아래 오른쪽 대각선으로 이동하며 5개인 점을 찾는다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 20
int arr[MAX][MAX];

int dx[] = {1, 0, 1,-1};
int dy[] = {0, 1, 1,1};

bool InRange(int x, int y) {
    return (1 <= x && x <= 19 && 1 <= y && y <= 19);
}

bool CheckNum(int i, int j) {
    int curNum = arr[i][j];

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;
        int curx = j;
        int cury = i;

        while (true) {
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];

            if (!InRange(nx, ny) || arr[ny][nx] != curNum) {
                break;
            }

            count++;
            curx = nx;
            cury = ny;
        }

        if (count == 5) {
            cout << curNum << '\n';
            cout << i+2*dy[dir] << " " << j+2*dx[dir] << '\n';
            return true;
        }
    }

    return false;
}

int main() {
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            if (arr[i][j] == 1 || arr[i][j] == 2) {
                if (CheckNum(i, j)) {
                    return 0;
                }
            }
        }
    }

    cout << "0\n";
    return 0;
}

```

# 문제
https://inha.codetree.ai/missions/5/problems/find-hidden-words-2/submissions
# 풀이
L 글자를 기준으로 이동할 수 있는 모든 경우의 수를 계산하며 LEE가 몇번 나오는지 구한다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 51
char arr[MAX][MAX];

int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={-1,-1,0,1,1,1,0,-1};

int checkLEE(int i, int j){
    int num=0;
    for(int k=0; k<8; k++){
        int nx = j+ dx[k];
        int ny = i + dy[k];
        if(arr[ny][nx]=='E'){
            if(arr[ny+dy[k]][nx+dx[k]]=='E')
                num+=1;
        }
    }
    return num;
}

int main() {
    int n,m;
    int num=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]=='L'){
                num+=checkLEE(i,j);
            }
        }
    }
    cout<<num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/best-place-of-13-2/explanation
# 풀이
모든 경우를 탐색하며 문제를 해결한다.
# 코드
``` 
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 21

int arr[MAX][MAX];
int n;

int main() {
    int max_num = INT_MIN;
    cin >> n;

    for (int i = 0; i < n; i++) { // 첫 번째 반복문 수정
        for (int j = 0; j < n; j++) { // 두 번째 반복문 수정
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) { // 첫 번째 반복문 수정
        for (int j = 0; j < n - 2; j++) { // 두 번째 반복문 수정
            for (int k = 0; k < n; k++) { // 세 번째 반복문 수정
                for (int l = 0; l < n - 2; l++) { // 네 번째 반복문 수정
                    if (i == k && abs(j - l) <= 2)
                        continue;
                    int cnt1 = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
                    int cnt2 = arr[k][l] + arr[k][l + 1] + arr[k][l + 2];
                    max_num = max(max_num, cnt1 + cnt2);
                }
            }
        }
    }
    cout << max_num << '\n';
    return 0;
}

```

# 문제

# 풀이

# 코드
``` 

```
