#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, b;
int ans;
int arr[21];
bool visited[21];

void backtracking(int sum, int idx)
{
  if (sum >= b)
  {
    ans = min(ans, sum - b);
    return;
  }

  for (int i = idx; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      backtracking(sum + arr[i], i);
      visited[i] = false;
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    memset(visited, false, sizeof(visited));
    ans = 0;
    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      ans += arr[i];
    }

    sort(arr, arr + n);

    backtracking(0, 0);
    cout << "#" << k << " " << ans << '\n';
  }
}