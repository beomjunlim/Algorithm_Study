#include <iostream>
#include <queue>
using namespace std;

int map[101];
bool visited[101];

void bfs(int start, int cnt)
{
  queue<pair<int, int>> q;
  q.push(make_pair(start, cnt));
  visited[start] = true;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (x == 100)
    {
      cout << y << '\n';
      return;
    }

    for (int i = 1; i <= 6; i++)
    {
      int nx = x + i;
      if (nx > 100 || visited[nx])
        continue;
      if (map[nx] > 0)
        nx = map[nx];
      q.push(make_pair(nx, y + 1));
      visited[nx] = true;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y;
  cin >> n >> m;

  for (int i = 0; i < n + m; i++)
  {
    cin >> x >> y;
    map[x] = y;
  }

  bfs(1, 0);
}