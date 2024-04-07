#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 < x && x <= n && 0 < y && y <= m;
}

int bfs()
{
  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(1, make_pair(1, 0)));
  visited[1][1][0] = 1;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second.first;
    int wall = q.front().second.second;
    q.pop();

    if (x == n && y == m)
      return visited[x][y][wall];

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!InRange(nx, ny))
        continue;

      if (arr[nx][ny] == 1 && !wall)
      {
        visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
        q.push(make_pair(nx, make_pair(ny, wall + 1)));
      }
      if (arr[nx][ny] == 0 && !visited[nx][ny][wall])
      {
        visited[nx][ny][wall] = visited[x][y][wall] + 1;
        q.push(make_pair(nx, make_pair(ny, wall)));
      }
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }

  cout << bfs() << '\n';
}