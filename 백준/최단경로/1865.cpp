#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int n, m, w, s, e, t;
int dist[501];

bool bellmanFord(int start, vector<pair<int, pair<int, int>>> road)
{
  dist[start] = 0;

  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 0; j < road.size(); j++)
    {
      int from = road[j].first;
      int to = road[j].second.first;
      int cost = road[j].second.second;

      if (dist[to] > dist[from] + cost)
      {
        dist[to] = dist[from] + cost;

        if (i == n)
          return true;
      }
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int CT;
  cin >> CT;

  while (CT > 0)
  {
    vector<pair<int, pair<int, int>>> road;
    cin >> n >> m >> w;

    for (int i = 1; i <= n; i++)
    {
      dist[i] = INF;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> s >> e >> t;
      road.push_back(make_pair(s, make_pair(e, t)));
      road.push_back(make_pair(e, make_pair(s, t)));
    }

    for (int i = 0; i < w; i++)
    {
      cin >> s >> e >> t;
      road.push_back(make_pair(s, make_pair(e, -t)));
    }

    if (bellmanFord(1, road))
    {
      cout << "YES" << '\n';
    }
    else
    {
      cout << "NO" << '\n';
    }

    CT--;
  }
}