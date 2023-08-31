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

# 풀이

# 코드
``` 

```
