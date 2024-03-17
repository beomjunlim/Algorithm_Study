#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  dp[1][0] = arr[1];
  dp[1][1] = arr[1];
  int ans = arr[1];

  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]); // 제거하지 않고 이번 숫자 제거, 이미 제거한 합 + 이번 숫자
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }

  cout << ans << '\n';
}