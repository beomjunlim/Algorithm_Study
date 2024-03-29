#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];
int cnt[1001][1001];
bool visited[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

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

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (InRange(nx, ny) && arr[nx][ny] == 1 && !visited[nx][ny])
      {
        visited[nx][ny] = true;
        cnt[nx][ny] = cnt[x][y] + 1;
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
      cin >> arr[i][j];
      if (arr[i][j] == 2)
      {
        visited[i][j] = true;
        q.push(make_pair(i, j));
      }
    }
  }

  bfs();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && arr[i][j] == 1)
      {
        cout << -1 << " ";
      }
      else
      {
        cout << cnt[i][j] << " ";
      }
    }
    cout << '\n';
  }
}