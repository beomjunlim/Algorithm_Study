#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

int cnt[20001];
vector<pair<int, int>> map[20001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v, e, start;
  cin >> v >> e >> start;

  for (int i = 1; i <= v; i++)
  {
    cnt[i] = INT_MAX;
  }

  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    map[u].push_back(make_pair(v, w));
  }

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  cnt[start] = 0;

  while (!pq.empty())
  {
    int dis = -pq.top().first;
    int pre = pq.top().second;
    pq.pop();

    for (int i = 0; i < map[pre].size(); i++)
    {
      int next = map[pre][i].first;
      int next_dis = map[pre][i].second;

      if (cnt[next] > dis + next_dis)
      {
        cnt[next] = dis + next_dis;
        pq.push(make_pair(-cnt[next], next));
      }
    }
  }

  for (int i = 1; i <= v; i++)
  {
    if (cnt[i] == INT_MAX)
      cout << "INF" << '\n';
    else
      cout << cnt[i] << '\n';
  }
}