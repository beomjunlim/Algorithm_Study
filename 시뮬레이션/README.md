# 문제
https://inha.codetree.ai/missions/5/problems/move-in-direction/introduction

# 풀이
문제 풀이는 입력 문자열의 경우에 따라서 이동하는 방법을 다르게하여서 풀었다.  
풀이에서 dx, dy를 이용하는 풀이도 있다는 것을 참고하였다.

# 코드
``` 
#include <iostream>
using namespace std;


int main() {
    int x,y,n;
    x=y=0;
    cin>>n;
    for(int i=0; i<n; i++){
        char s;
        int num;
        cin>>s>>num;
        if(s=='N'){
            y+=num;
        }
        if(s=='E'){
            x+=num;
        }
        if(s=='S'){
            y-=num;
        }
        if(s=='W'){
            x-=num;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/text-based-commands2/introduction
# 풀이
이 문제 또한 dx, dy를 이용하지않고 풀었다.  
현재 바라보고 있는 방향을 저장하는 문자열을 이용해서 명령 문자가 들어올 때 명령을 수행하도록 하였다.
# 코드
```
#include <iostream>
using namespace std;

int main() {
    string s;
    char c='N';
    int x,y;
    x=y=0;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='L'){
            if(c=='N')
                c='W';
            else if(c=='S')
                c='E';
            else if(c=='W')
                c='S';
            else if(c=='E')
                c='N';
        }
        if(s[i]=='R'){
            if(c=='N')
                c='E';
            else if(c=='S')
                c='W';
            else if(c=='W')
                c='N';
            else if(c=='E')
                c='S';
        }
        if(s[i]=='F'){
            if(c=='N')
                y+=1;
            if(c=='S')
                y-=1;
            if(c=='W')
                x-=1;
            if(c=='E')
                x+=1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/place-more-than-3-ones/introduction
# 풀이
dx, dy를 사용하여 풀었다.  
먼저 이동을 하고 범위안에 있는지를 점검하고 그 후 1이 있을 경우 sum을 증가시켜 sum이 3보다 크거나 같을 경우 res를 증가 시키는 방법을 이용했다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
  int n;
  int res = 0;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }

  int sum, nx, ny;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      sum = 0;
      for (int k = 0; k < 4; k++)
      {
        nx = dx[k] + j;
        ny = dy[k] + i;
        if (nx > 0 && nx < n + 1 && ny > 0 && ny < n + 1)
        {
          if (arr[ny][nx] == 1)
            sum += 1;
        }
      }
      if (sum >= 3)
        res += 1;
    }
  }
  cout << res << '\n';
  return 0;
}

```

# 문제
https://inha.codetree.ai/missions/5/problems/small-marble-movement/introduction
# 풀이
업 다운, 오른쪽, 왼쪽 방향에 따라 방법이 다르므로  
먼저 x 좌표를 이용하는지 y 좌표를 이용하는지를 나누고 sw를 이용하여 그 안에서 경우를 또 나누었다.
# 코드
```
#include <iostream>
using namespace std;

int main()
{
  int n, t, a, b;
  char s;
  bool sw = true;
  cin >> n >> t;
  cin >> a >> b >> s;
  if (s == 'L' || s == 'R')
  {
    if (s == 'L')
      sw = false;
    for (int i = 0; i < t; i++)
    {
      if (sw)
      {
        b += 1;
        if (b == n + 1)
        {
          b -= 1;
          sw = !sw;
        }
      }
      else
      {
        b -= 1;
        if (b == 0)
        {
          b += 1;
          sw = !sw;
        }
      }
    }
  }
  else if (s == 'U' || s == 'D')
  {
    if (s == 'U')
      sw = false;
    for (int i = 0; i < t; i++)
    {
      if (sw)
      {
        a += 1;
        if (a == n + 1)
        {
          a -= 1;
          sw = !sw;
        }
      }
      else
      {
        a -= 1;
        if (a == 0)
        {
          a += 1;
          sw = !sw;
        }
      }
    }
  }
  cout << a << " " << b << '\n';
  return 0;
}

```

# 문제
https://inha.codetree.ai/missions/5/problems/snail-number-square/introduction
# 풀이
dir_num 을 이용하여 동서남북 방향을 제어하는 방법을 알았다.  
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX][MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y, int m, int n)
{
  return (0 < x && x <= m && 0 < y && y <= n);
}


int main()
{
  int n, m;
  int dir_num = 0;
  cin >> n >> m;
  int x = 1, y = 1;
  arr[y][x] = 1;

  for (int i = 2; i <= n * m; i++)
  {
    int nx = x + dx[dir_num], ny = y + dy[dir_num];
    if (arr[ny][nx] != 0 || !InRange(nx, ny, m, n))
      dir_num = (dir_num + 1) % 4;
    x = x + dx[dir_num];
    y = y + dy[dir_num];
    arr[y][x] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}

```

# 문제
https://inha.codetree.ai/missions/5/problems/come-back/description
# 풀이
시작 좌표는 (0,0) 으로 설정하고, 먼저 n번의 명령을 입력받는다.  
그러고 그 명령을 수행하면서 만약 x, y 좌표가 (0,0)이 된다면 sw가 true가 되고 출력하도록한다.  
만일 다시 돌아오지 않는다면 sw는 false가 되어 -1을 출력한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
char ch[MAX];

int main()
{
  int n;
  cin >> n;
  int x = 0, y = 0;
  int sum = 0;
  bool sw = false;
  for (int i = 0; i < n; i++)
  {
    cin >> ch[i] >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    char c;
    int a;
    c = ch[i];
    a = arr[i];
    if (c == 'N')
    {
      for (int j = 0; j < a; j++)
      {
        y += 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'S')
    {
      for (int j = 0; j < a; j++)
      {
        y -= 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'W')
    {
      for (int j = 0; j < a; j++)
      {
        x -= 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'E')
    {
      for (int j = 0; j < a; j++)
      {
        x += 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (sw)
      break;
  }
  if (sw)
    cout << sum << '\n';
  else
    cout << "-1" << '\n';
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/come-back-2/description
# 풀이
dx, dy 방법을 이용하고, dir_num을 사용하여 문제를 풀었다.  
시계방향을 기준으로 이용하였으므로 시계반대 방향의 경우는 +3을 해야하는게 다르다.
# 코드
```
#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main()
{
  string s;
  cin >> s;
  int x = 0, y = 0;
  int dir_num = 0;
  int sum = 0;
  for (int i = 0; i < s.length(); i++)
  {
    sum += 1;
    if (s[i] == 'F')
    {
      x = x + dx[dir_num];
      y = y + dy[dir_num];
      if (x == 0 && y == 0)
        break;
    }
    if (s[i] == 'R')
    {
      dir_num = (dir_num + 1) % 4;
    }
    if (s[i] == 'L')
    {
      dir_num = (dir_num + 3) % 4;
    }
  }
  cout << sum << '\n';
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/comfortable-state-on-the-grid/submissions
# 풀이
dx, dy, InRange()를 이용해서 색칠할 때는 1을 넣고 그외에는 0으로 색칠 유무를 구분하도록 하여 문제를 해결했다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX][MAX];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool InRange(int x, int y, int n){
    return (0<x&&x<=n&&0<y&&y<=n);
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>y>>x;
        arr[y][x]=1;
        int num=0;
        for(int j=0; j<4; j++){
            int nx = x +dx[j], ny = y + dy[j];
            if(InRange(nx,ny,n)&&arr[ny][nx]==1)
                num+=1;
        }
        if(num==3)
            cout<<"1"<<'\n';
        else
            cout<<"0"<<'\n';
    }
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/shoot-a-laser-in-the-mirror-2/description
# 풀이
XOR 연산자 비트 연산을 이 코드를 통해 알게되었다. 비트연산을 생각하지 못했다.
# 코드
```
#include <iostream>

#define MAX_N 1000
#define DIR_NUM 4

using namespace std;

int n;
char arr[MAX_N][MAX_N];

int start_num;
int x, y, move_dir;

// 주어진 숫자에 따라
// 시작 위치와 방향을 구합니다.
void Initialize(int num) {
    if(num <= n) {
        x = 0; y = num - 1; move_dir = 0;
    }
    else if(num <= 2 * n) {
        x = num - n - 1; y = n - 1; move_dir = 1;
    }
    else if(num <= 3 * n) {
        x = n - 1; y = n - (num - 2 * n); move_dir = 2;
    }
    else {
        x = n - (num - 3 * n); y = 0; move_dir = 3;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// (x, y)에서 시작하여 next_dir 방향으로
// 이동한 이후의 위치를 구합니다.
void Move(int next_dir) {
    int dx[DIR_NUM] = {1,  0, -1, 0};
    int dy[DIR_NUM] = {0, -1,  0, 1};
    
    x += dx[next_dir];
    y += dy[next_dir];
    move_dir = next_dir;
}

int Simulate() {
    int move_num = 0;
    while(InRange(x, y)) {
        // 0 <-> 1 / 2 <-> 3
        if(arr[x][y] == '/')
            Move(move_dir ^ 1);
        // 0 <-> 3 / 1 <-> 2
        else
            Move(3 - move_dir);
        
        move_num += 1;
    }
    
    return move_num;
}

int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    cin >> start_num;
 
    // 시작 위치와 방향을 구합니다.
    Initialize(start_num);
    // (x, y)에서 move_dir 방향으로 시작하여
    // 시뮬레이션을 진행합니다.
    int move_num = Simulate();
    
    cout << move_num;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/snail-number-square-2/submissions
# 풀이
dx, dy를 이용하여 다음 이동할 경우를 계산하고, InRange()를 이용하여 격자 내인지를 파악한다.  
먼저 이동을 시키고 이를 만족하지 못할 경우 dir_num을 바꿔준다.  그러고 i값을 넣어준다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool InRange(int x, int y, int n, int m)
{
  return (0 < x && x <= m && 0 < y && y <= n);
}

int main()
{
  int n, m;
  cin >> n >> m;

  int x = 1, y = 1;
  arr[y][x] = 1;
  int dir_num = 0;
  for (int i = 2; i <= n * m; i++)
  {
    int nx = x + dx[dir_num], ny = y + dy[dir_num];
    if (arr[ny][nx] != 0 || !InRange(nx, ny, n, m))
    {
      dir_num = (dir_num + 1) % 4;
    }
    x = x + dx[dir_num];
    y = y + dy[dir_num];
    arr[y][x] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/snail-alphabet-square/description
# 풀이
char형 배열을 선언하고 초기값은 null 값이들어가기 때문에 이를 이용해서 방문햇는지 아닌지 확인한다.  
대문자 Z까지 갔으면 다시 A부터 시작하므로 이를 잘 생각해서 코드를 작성한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101
char arr[MAX][MAX];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int dir_num;

bool InRange(int x, int y, int m, int n)
{
  return (0 < x && x <= m && 0 < y && y <= n);
}

int main()
{
  int n, m;
  cin >> n >> m;
  int x = 1, y = 1;
  arr[y][x] = 65;
  dir_num = 1;
  for (int i = 1; i < n * m; i++)
  {
    int nx = x + dx[dir_num], ny = y + dy[dir_num];
    if (arr[ny][nx] != 0 || !InRange(nx, ny, m, n))
      dir_num = (dir_num + 1) % 4;
    x = x + dx[dir_num];
    y = y + dy[dir_num];
    int num = (i % 26) + 65;
    arr[y][x] = num;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/snail-start-from-center/submissions
# 풀이
이전 문제와 달리 가운데부터 시작한다. 따라서 움직이는 칸이 증가할 때의 방향을 생각하고 기준을 정해서 코드를 작성한다.  
돌다가 규격에 벗어난다면 그 때 while문을 종료하는 방법으로 코드를 작성하였다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int dir_num;
int x, y;
int n;

bool InRange(int x, int y, int n)
{
  return (0 < x && x <= n && 0 < y && y <= n);
}

int main()
{

  cin >> n;

  x = y = (n / 2 + 1);
  dir_num = 0;
  int num = 1;
  int move_num = 1;

  while (InRange(x, y, n))
  {
    for (int i = 0; i < move_num; i++)
    {
      arr[y][x] = num++;
      x = x + dx[dir_num];
      y = y + dy[dir_num];
      if (!InRange(x, y, n))
        break;
    }
    dir_num = (dir_num + 1) % 4;
    if (dir_num == 0 || dir_num == 2)
      move_num++;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/add-all-the-numbers-on-the-path/submissions
# 풀이
지금까지 배운 내용을 토대로 dx, dy를 이용해서 각 명령어에 따른 명령을 수행했다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int dir_num;
int x, y;

bool InRange(int x, int y, int n)
{
  return (0 < x && x <= n && 0 < y && y <= n);
}

int main()
{
  int n, t;
  string s;
  int sum = 0;
  cin >> n >> t;
  cin >> s;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }

  x = y = (n / 2 + 1);
  sum += arr[y][x];
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'F')
    {
      int nx = x + dx[dir_num];
      int ny = y + dy[dir_num];
      if (!InRange(nx, ny, n))
        continue;
      else
      {
        x = x + dx[dir_num];
        y = y + dy[dir_num];
        sum += arr[y][x];
      }
    }

    if (s[i] == 'L')
    {
      dir_num = (dir_num + 3) % 4;
    }

    if (s[i] == 'R')
    {
      dir_num = (dir_num + 1) % 4;
    }
  }
  cout << sum << '\n';
  return 0;
}
```






