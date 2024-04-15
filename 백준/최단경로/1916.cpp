#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int dist[1001];
vector<pair<int, int>> map[1001];

void dijkstra(int start, int end)
{
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty())
  {
    int cnt = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < cnt)
      continue;

    if (node == end)
    {
      cout << dist[node] << '\n';
      break;
    }

    for (int i = 0; i < map[node].size(); i++)
    {
      int next_node = map[node][i].first;
      int next_cnt = map[node][i].second;

      if (dist[next_node] > next_cnt + cnt)
      {
        dist[next_node] = next_cnt + cnt;
        pq.push(make_pair(-dist[next_node], next_node));
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, start, end;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    map[a].push_back(make_pair(b, c));
  }
  cin >> start >> end;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }

  dijkstra(start, end);
}