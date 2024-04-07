#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int ans[9];
bool visited[9];
int n, m;

void backTracking(int num)
{
  if (num == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }

  int tmp = 0;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && arr[i] != tmp)
    {
      visited[i] = true;
      ans[num] = arr[i];
      tmp = ans[num];
      backTracking(num + 1);
      visited[i] = false;
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

  backTracking(0);
}