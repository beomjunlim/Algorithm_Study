#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int n, m;
bool visited[101];
int friends[101][101];

int bfs(int start)
{
  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  visited[start] = true;
  int cnt = 0;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 1; i <= n; i++)
    {
      if (friends[x][i] == 1 && !visited[i])
      {
        visited[i] = true;
        cnt += (y + 1);
        q.push(make_pair(i, y + 1));
      }
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int sum = INT_MAX;
  int ans = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    friends[a][b] = 1;
    friends[b][a] = 1;
  }

  for (int i = 1; i <= n; i++)
  {
    memset(visited, false, sizeof(visited));
    int cnt = bfs(i);
    if (sum > cnt)
    {
      sum = cnt;
      ans = i;
    }
  }
  cout << ans << '\n';
}