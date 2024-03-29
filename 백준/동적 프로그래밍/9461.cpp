#include <iostream>
using namespace std;

long long dp[101];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n;
  cin >> t;

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;

  for (int i = 4; i <= 100; i++)
  {
    dp[i] = dp[i - 2] + dp[i - 3];
  }

  while (t > 0)
  {
    cin >> n;
    cout << dp[n] << '\n';
    t--;
  }
}