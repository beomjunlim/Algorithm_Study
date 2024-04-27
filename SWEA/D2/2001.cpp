#include <iostream>
using namespace std;

int arr[15][15];
int sum[15][15];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> arr[i][j];
      }
    }

    sum[0][0] = arr[0][0];

    for (int i = 1; i < n; i++)
    {
      sum[0][i] = sum[0][i - 1] + arr[0][i];
      sum[i][0] = sum[i - 1][0] + arr[i][0];
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < n; j++)
      {
        sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j]);
      }
    }

    int ans = 0;

    for (int i = m - 1; i < n; i++)
    {
      for (int j = m - 1; j < n; j++)
      {
        if (i - m < 0 && j - m < 0)
          ans = max(ans, sum[i][j]);
        if (i - m >= 0 && j - m < 0)
          ans = max(ans, sum[i][j] - sum[i - m][j]);
        if (i - m < 0 && j - m >= 0)
          ans = max(ans, sum[i][j] - sum[i][j - m]);
        if (i - m >= 0 && j - m >= 0)
          ans = max(ans, sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]);
      }
    }

    cout << "#" << k << " " << ans << '\n';
  }
}