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
