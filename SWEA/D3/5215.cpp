#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[21][10001];

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    int n, l;
    int ans = 0;
    vector<pair<int, int>> hamburger;

    cin >> n >> l;

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= l; j++)
      {
        dp[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++)
    {
      int score, calorie;
      cin >> score >> calorie;
      hamburger.push_back(make_pair(score, calorie));
    }

    dp[0][0] = 0;
    dp[0][hamburger[0].second] = hamburger[0].first;

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= l; j++)
      {
        if (j >= hamburger[i].second)
        {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - hamburger[i].second] + hamburger[i].first);
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
        ans = max(ans, dp[i][j]);
      }
    }

    cout << "#" << k << " " << ans << '\n';
  }
}