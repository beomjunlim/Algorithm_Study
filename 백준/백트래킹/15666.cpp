#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int ans[10];

void backtracking(int x, int num)
{
  if (num == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << ans[i] << " ";
    }
    cout << '\n';
    return;
  }

  int last = 0;

  for (int i = x; i < n; i++)
  {
    if (arr[i] != last)
    {
      ans[num] = arr[i];
      last = ans[num];
      backtracking(i, num + 1);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  backtracking(0, 0);
}