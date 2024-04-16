#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define INF 98765432

int n, e;
int node_a, node_b;
vector<pair<int, int>> road[801];
int dist[801];
int answer = 0;

void Initialization()
{
  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }
}

void dijkstra(int start)
{
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty())
  {
    int dis = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < dis)
      continue;

    for (int i = 0; i < road[node].size(); i++)
    {
      int next_node = road[node][i].first;
      int next_dis = road[node][i].second;

      if (dist[next_node] > next_dis + dis)
      {
        dist[next_node] = next_dis + dis;
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

  cin >> n >> e;

  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    road[a].push_back(make_pair(b, c));
    road[b].push_back(make_pair(a, c));
  }

  cin >> node_a >> node_b;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }

  int answer_a = 0;
  int answer_b = 0;
  Initialization();
  dijkstra(1);

  answer_a += dist[node_a];
  answer_b += dist[node_b];

  Initialization();
  dijkstra(node_a);
  answer_a += dist[node_b];
  answer_b += dist[n];

  Initialization();
  dijkstra(node_b);
  answer_a += dist[n];
  answer_b += dist[node_a];

  answer = min(answer_a, answer_b);

  if (answer >= INF)
  {
    answer = -1;
  }
  cout << answer << '\n';
}