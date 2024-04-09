#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321
int n, m, x;
int dis[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> x;
  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dis[i][j] = INF;
      if (i == j)
        dis[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    dis[a][b] = c;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, dis[i][x] + dis[x][i]);
  }
  cout << ans << '\n';
}