#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, h;
int tomato[101][101][101];
bool visited[101][101][101];
int cnt[101][101][101];
int tomato_cnt = 0;
int ans = 0;
bool sw = false;
int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, -1, 1, 0, 0};
queue<pair<int, pair<int, int>>> q;

bool InRange(int x, int y, int z)
{
  return 0 <= x && x < h && 0 <= y && y < n && 0 <= z && z < m;
}

void dfs()
{

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second.first;
    int z = q.front().second.second;
    q.pop();

    if (tomato_cnt == 0)
    {
      sw = true;
      break;
    }

    for (int i = 0; i < 6; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if (InRange(nx, ny, nz) && tomato[nx][ny][nz] == 0 && !visited[nx][ny][nz])
      {
        cnt[nx][ny][nz] = cnt[x][y][z] + 1;
        visited[nx][ny][nz] = true;
        tomato_cnt--;
        ans = max(ans, cnt[nx][ny][nz]);
        q.push(make_pair(nx, make_pair(ny, nz)));
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        cin >> tomato[i][j][k];
        if (tomato[i][j][k] == 0)
          tomato_cnt++;
        if (tomato[i][j][k] == 1)
        {
          q.push(make_pair(i, make_pair(j, k)));
          visited[i][j][k] = true;
          cnt[i][j][k] = 0;
        }
      }
    }
  }

  dfs();

  if (sw)
  {
    cout << ans << '\n';
  }
  else
  {
    cout << -1 << '\n';
  }
}