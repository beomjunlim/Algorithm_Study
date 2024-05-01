#include <iostream>
using namespace std;

int n, k;
int ans;
int arr[21];
int dp[21][21];

void cnt(int idx, int sum)
{
  if (sum > k)
    return;

  if (sum == k)
  {
    ans++;
    return;
  }

  for (int i = idx; i < n; i++)
  {
    cnt(i + 1, sum + arr[i]);
  }
}

int main()
{
  int l;
  cin >> l;

  for (int t = 1; t <= l; t++)
  {
    ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    cnt(0, 0);
    cout << "#" << t << " " << ans << '\n';
  }
}
