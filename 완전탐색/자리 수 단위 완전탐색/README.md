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

# 풀이

# 코드
``` 

```
