#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

long long dp[50001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    dp[i] = INT_MAX;
  }

  dp[1] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sqrt(i); j++)
    {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  cout << dp[n] << '\n';
}