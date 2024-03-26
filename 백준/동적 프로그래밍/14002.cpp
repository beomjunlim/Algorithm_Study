#include <iostream>
#include <stack>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int ans = 0;
  int idx = 0;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    dp[i] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    if (ans < dp[i])
    {
      ans = dp[i];
      idx = i;
    }
  }

  stack<int> st;
  st.push(arr[idx]);
  int temp = idx;

  for (int i = idx; i >= 0; i--)
  {
    if (dp[temp] - 1 == dp[i])
    {
      st.push(arr[i]);
      temp = i;
    }
  }

  cout << ans << '\n';

  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}