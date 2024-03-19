#include <iostream>
using namespace std;

int arr[1000];
bool visited[1000];
int dp[1000];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  visited[0] = true;

  for (int i = 0; i < n - 1; i++)
  {
    if (visited[i])
    {
      for (int j = 0; j <= arr[i]; j++)
      {
        if (!visited[i + j])
        {
          dp[i + j] = dp[i] + 1;
          visited[i + j] = true;
        }
      }
    }
  }

  if (!visited[n - 1])
    cout << -1 << '\n';
  else
    cout << dp[n - 1] << '\n';
}