#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

int n;
int ans;
int arr[100][100];
bool visited[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int a, int b)
{
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push(make_pair(0, make_pair(a, b)));
  visited[a][b] = true;

  while (!pq.empty())
  {
    int cnt = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    if (x == n - 1 && y == n - 1)
    {
      ans = min(ans, cnt);
      return;
    }

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (InRange(nx, ny) && !visited[nx][ny])
      {
        visited[nx][ny] = true;
        pq.push(make_pair(-(cnt + arr[nx][ny]), make_pair(nx, ny)));
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    ans = INF;
    cin >> n;

    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 100; j++)
      {
        visited[i][j] = false;
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%1d", &arr[i][j]);
      }
    }

    bfs(0, 0);
    cout << "#" << k << " " << ans << '\n';
  }
}