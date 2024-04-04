#include <iostream>
#include <queue>
using namespace std;

char map[601][601];
bool visited[601][601];
int n, m;
int ans = 0;
queue<pair<int, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs()
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (map[x][y] == 'P')
    {
      ans++;
    }

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (InRange(nx, ny) && map[nx][ny] != 'X' && !visited[nx][ny])
      {
        visited[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
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
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 'I')
      {
        q.push(make_pair(i, j));
        visited[i][j] = true;
      }
    }
  }

  bfs();

  if (ans == 0)
  {
    cout << "TT" << '\n';
  }
  else
  {
    cout << ans << '\n';
  }
}