#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int start = 0;
int maxDis = 0;
bool visited[100001];
vector<pair<int, int>> map[100001];

void dfs(int node, int dis)
{
  visited[node] = true;

  if (maxDis < dis)
  {
    start = node;
    maxDis = dis;
  }

  for (int i = 0; i < map[node].size(); i++)
  {
    int next_node = map[node][i].first;
    int next_dis = map[node][i].second;

    if (!visited[next_node])
    {
      dfs(next_node, dis + next_dis);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int node, a, b;
    cin >> node;
    while (1)
    {
      cin >> a;
      if (a == -1)
        break;
      cin >> b;
      map[node].push_back(make_pair(a, b));
    }
  }

  dfs(1, 0);
  memset(visited, false, sizeof(visited));
  dfs(start, 0);

  cout << maxDis << '\n';
}