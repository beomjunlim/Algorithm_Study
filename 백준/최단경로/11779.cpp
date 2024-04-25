#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, m;
vector<pair<int, int>> nodes[1001];
int dist[1001];
int route[1001];

void dijkstra(int start, int end)
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
      int next_node = nodes[node][i].first;
      int next_cost = nodes[node][i].second + cost;

      if (dist[next_node] > next_cost)
      {
        dist[next_node] = next_cost;
        route[next_node] = node;
        pq.push(make_pair(-next_cost, next_node));
      }
    }
  }

  vector<int> Route;
  cout << dist[end] << '\n';
  int temp = end;
  while (1)
  {
    Route.push_back(temp);
    temp = route[temp];
    if (temp == 0)
      break;
  }

  cout << Route.size() << '\n';

  for (int i = Route.size() - 1; i >= 0; i--)
  {
    cout << Route[i] << " ";
  }
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[a].push_back(make_pair(b, c));
  }

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }

  int start, end;
  cin >> start >> end;

  dijkstra(start, end);
}