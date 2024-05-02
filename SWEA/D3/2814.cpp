#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int ans;
int arr[11][11];
bool visited[11];

void dfs(int start, int cnt)
{
  ans = max(ans, cnt);

  for (int i = 1; i <= n; i++)
  {
    if (arr[start][i] && !visited[i])
    {
      visited[i] = true;
      dfs(i, cnt + 1);
      visited[i] = false;
    }
  }
}

int main()
{
  int k;
  cin >> k;

  for (int t = 1; t <= k; t++)
  {
    cin >> n >> m;
    memset(visited, false, sizeof(visited));

    ans = 0;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        arr[i][j] = 0;
      }
    }

    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      arr[a][b] = 1;
      arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
      visited[i] = true;
      dfs(i, 1);
      visited[i] = false;
    }

    cout << "#" << t << " " << ans << '\n';
  }
}