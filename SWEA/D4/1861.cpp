#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int cnt[1001][1001];
int arr[1001][1001];
int ans_start = 0;
int ans_num = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < n;
}

int dfs(int x, int y)
{
  if (cnt[x][y] != -1)
    return cnt[x][y];

  cnt[x][y] = 1;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (InRange(nx, ny) && arr[nx][ny] - arr[x][y] == 1)
    {
      cnt[x][y] = cnt[x][y] + dfs(nx, ny);
    }
  }

  return cnt[x][y];
}

int main()
{
  int k;
  cin >> k;

  for (int t = 1; t <= k; t++)
  {
    ans_start = 0;
    ans_num = 0;
    memset(cnt, -1, sizeof(cnt));
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int result = dfs(i, j);
        if (result > ans_num)
        {
          ans_start = arr[i][j];
          ans_num = result;
        }
        else if (result == ans_num)
        {
          ans_start = min(ans_start, arr[i][j]);
        }
      }
    }

    cout << "#" << t << " " << ans_start << " " << ans_num << '\n';
  }
}