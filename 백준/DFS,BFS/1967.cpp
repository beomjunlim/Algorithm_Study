#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
int ans = 0;
bool visited[10001];

vector<pair<int, int>> map[10001];

void dfs(int num, int sum)
{
  visited[num] = true;

  for (int i = 0; i < map[num].size(); i++)
  {
    if (map[num][i].second != 0 && !visited[map[num][i].first])
    {
      dfs(map[num][i].first, sum + map[num][i].second);
    }
  }
  ans = max(ans, sum);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    map[a].push_back(make_pair(b, c));
    map[b].push_back(make_pair(a, c));
  }

  for (int i = 1; i <= n; i++)
  {
    memset(visited, false, sizeof(visited));
    dfs(i, 0);
  }
  cout << ans << '\n';
}