#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m, r;
int region[101];
int map[101][101];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j)
      {
        map[i][j] = INF;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> region[i];
  }

  for (int i = 0; i < r; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    map[a][b] = c;
    map[b][a] = c;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        if (map[j][i] + map[i][k] < map[j][k])
          map[j][k] = map[j][i] + map[i][k];
      }
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    int temp = 0;
    for (int j = 1; j <= n; j++)
    {
      if (map[i][j] <= m)
      {
        temp += region[j];
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
}