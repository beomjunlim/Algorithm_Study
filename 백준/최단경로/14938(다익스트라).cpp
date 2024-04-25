#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, m, r;
int region[101];
vector<pair<int, int>> nodes[101];
int dist[101];

void dijkstra(int start)
{
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < cost)
      continue;

    for (int i = 0; i < nodes[node].size(); i++)
    {
      int next_cost = cost + nodes[node][i].second;

      if (next_cost < dist[nodes[node][i].first])
      {
        dist[nodes[node][i].first] = next_cost;
        pq.push(make_pair(-next_cost, nodes[node][i].first));
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int ans = 0;

  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++)
  {
    cin >> region[i];
  }

  for (int i = 0; i < r; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[a].push_back(make_pair(b, c));
    nodes[b].push_back(make_pair(a, c));
  }

  for (int i = 1; i <= n; i++)
  {
    int temp = 0;
    for (int j = 1; j <= n; j++)
    {
      dist[j] = INF;
    }

    dijkstra(i);

    for (int j = 1; j <= n; j++)
    {
      if (dist[j] <= m)
        temp += region[j];
    }
    ans = max(ans, temp);
  }

  cout << ans << '\n';
}