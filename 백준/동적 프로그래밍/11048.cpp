#include <iostream>
using namespace std;

int candy[1001][1001];
int dp[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> candy[i][j];
    }
  }

  for (int i = 1; i <= m; i++)
  {
    dp[1][i] = dp[1][i - 1] + candy[1][i];
  }

  for (int j = 1; j <= n; j++)
  {
    dp[j][1] = dp[j - 1][1] + candy[j][1];
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 2; j <= m; j++)
    {
      dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + candy[i][j];
    }
  }

  cout << dp[n][m];
}