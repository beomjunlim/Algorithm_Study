#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

vector<pair<int, int>> map[1001];
int dis[1001];

void bfs(int start)
{
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  dis[start] = 0;

  while (!pq.empty())
  {
    int node = pq.top().second;
    int cnt = -pq.top().first;
    pq.pop();

    for (int i = 0; i < map[node].size(); i++)
    {
      int next_node = map[node][i].first;
      int next_cnt = map[node][i].second + dis[node];

      if (next_cnt < dis[next_node])
      {
        dis[next_node] = next_cnt;
        pq.push(make_pair(-next_cnt, next_node));
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x;
  int ans = 0;
  cin >> n >> m >> x;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    map[a].push_back(make_pair(b, c));
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      dis[j] = INF;
    }
    bfs(i);
    int start_dis = dis[x];

    for (int j = 0; j <= n; j++)
    {
      dis[j] = INF;
    }

    bfs(x);
    int end_dis = dis[i];
    ans = max(ans, start_dis + end_dis);
  }
  cout << ans << '\n';
}