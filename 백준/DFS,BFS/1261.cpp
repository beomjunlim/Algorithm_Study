#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
int cnt[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 < x && x <= m && 0 < y && y <= n;
}

void bfs(int i, int j)
{
  queue<pair<int, int>> q;
  q.push({i, j});
  cnt[1][1] = 0;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (InRange(nx, ny))
      {
        if (arr[nx][ny] == 1)
        {
          if (cnt[nx][ny] > cnt[x][y] + 1)
          {
            cnt[nx][ny] = cnt[x][y] + 1;
            q.push({nx, ny});
          }
        }
        else
        {
          if (cnt[nx][ny] > cnt[x][y])
          {
            cnt[nx][ny] = cnt[x][y];
            q.push({nx, ny});
          }
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char a;
  cin >> n >> m;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> a;
      arr[i][j] = a - '0';
      cnt[i][j] = 100000;
    }
  }

  bfs(1, 1);
  cout << cnt[m][n];
}