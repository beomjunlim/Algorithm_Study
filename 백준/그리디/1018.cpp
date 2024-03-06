#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
char arr[MAX][MAX];
int ans = 64;

void Count(int x, int y)
{
  int black = 0;
  int white = 0;
  for (int i = x; i < x + 8; i++)
  {
    for (int j = y; j < y + 8; j++)
    {
      if ((i - x + j - y) % 2 == 0)
      {
        if (arr[i][j] == 'B')
          white++;
        else
          black++;
      }
      else
      {
        if (arr[i][j] == 'W')
          white++;
        else
          black++;
      }
    }
  }
  ans = min(ans, min(white, black));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i <= n - 8; i++)
  {
    for (int j = 0; j <= m - 8; j++)
    {
      Count(i, j);
    }
  }

  cout << ans << '\n';
}
