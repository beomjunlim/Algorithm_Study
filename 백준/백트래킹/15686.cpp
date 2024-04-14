#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ans = 987654321;
int map[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool chicken_visited[51];

int checkDist(int x, int y)
{
  int cnt = 987654321;

  for (int i = 0; i < chicken.size(); i++)
  {
    if (map[chicken[i].first][chicken[i].second] == 2)
    {
      cnt = min(cnt, abs(x - chicken[i].first) + abs(y - chicken[i].second));
    }
  }
  return cnt;
}

void backtracking(int start, int num)
{
  if (num == m)
  {
    int cnt = 0;
    for (int i = 0; i < house.size(); i++)
    {
      int x = house[i].first;
      int y = house[i].second;
      cnt += checkDist(x, y);
    }
    ans = min(ans, cnt);
  }

  for (int i = start; i < chicken.size(); i++)
  {
    int x = chicken[i].first;
    int y = chicken[i].second;
    if (!chicken_visited[i])
    {
      chicken_visited[i] = true;
      map[x][y] = 2;
      backtracking(i + 1, num + 1);
      chicken_visited[i] = false;
      map[x][y] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 1)
      {
        house.push_back(make_pair(i, j));
      }
      if (map[i][j] == 2)
      {
        map[i][j] = 0;
        chicken.push_back(make_pair(i, j));
      }
    }
  }
  backtracking(0, 0);
  cout << ans << '\n';
}