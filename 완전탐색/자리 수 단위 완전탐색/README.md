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

# 풀이

# 코드
``` 

```
