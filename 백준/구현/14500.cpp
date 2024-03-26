#include <iostream>
using namespace std;

int n, m;
int arr[501][501];
int ans = 0;

void Myfunction(int x, int y)
{
  if (x + 1 < n && y + 1 < m)
  {
    int cnt = arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x + 1][y + 1];
    ans = max(ans, cnt);
  }

  if (x + 3 < n)
  {
    int cnt = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 3][y];
    ans = max(ans, cnt);
  }

  if (y + 3 < m)
  {
    int cnt = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x][y + 3];
    ans = max(ans, cnt);
  }

  if (x + 1 < n && y + 2 < m)
  {
    int cnt = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
    ans = max(ans, cnt - arr[x + 1][y] - arr[x + 1][y + 2]);
    ans = max(ans, cnt - arr[x][y] - arr[x][y + 2]);
    ans = max(ans, cnt - arr[x + 1][y + 1] - arr[x + 1][y + 2]);
    ans = max(ans, cnt - arr[x + 1][y] - arr[x + 1][y + 1]);
    ans = max(ans, cnt - arr[x][y + 1] - arr[x][y + 2]);
    ans = max(ans, cnt - arr[x][y] - arr[x][y + 1]);
    ans = max(ans, cnt - arr[x][y] - arr[x + 1][y + 2]);
    ans = max(ans, cnt - arr[x][y + 2] - arr[x + 1][y]);
  }

  if (x + 2 < n && y + 1 < m)
  {
    int cnt = arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y] + arr[x + 2][y + 1];
    ans = max(ans, cnt - arr[x][y + 1] - arr[x + 2][y + 1]);
    ans = max(ans, cnt - arr[x][y] - arr[x + 2][y]);
    ans = max(ans, cnt - arr[x + 1][y + 1] - arr[x + 2][y + 1]);
    ans = max(ans, cnt - arr[x + 1][y] - arr[x + 2][y]);
    ans = max(ans, cnt - arr[x][y + 1] - arr[x + 1][y + 1]);
    ans = max(ans, cnt - arr[x][y] - arr[x + 1][y]);
    ans = max(ans, cnt - arr[x][y] - arr[x + 2][y + 1]);
    ans = max(ans, cnt - arr[x][y + 1] - arr[x + 2][y]);
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
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      Myfunction(i, j);
    }
  }
  cout << ans << '\n';
}