#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define INF 987654321

int n;
int shark_x = 0;
int shark_y = 0;
int shark_size = 2;

bool eat = false;
int eat_fish = 0;
int cnt = 0;
int sea[21][21];
bool visited[21][21];
int dist[21][21];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs()
{
  queue<pair<int, int>> q;
  q.push(make_pair(shark_x, shark_y));
  visited[shark_x][shark_y] = true;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (InRange(nx, ny) && !visited[nx][ny] && sea[nx][ny] <= shark_size)
      {
        visited[nx][ny] = true;
        dist[nx][ny] = dist[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> sea[i][j];
      if (sea[i][j] == 9)
      {
        sea[i][j] = 0;
        shark_x = i;
        shark_y = j;
      }
    }
  }

  while (1)
  {
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    int min_dist = INF;
    int min_x, min_y;
    bfs();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (sea[i][j] != 0 && sea[i][j] < shark_size && visited[i][j])
        {
          if (dist[i][j] < min_dist)
          {
            min_dist = dist[i][j];
            min_x = i;
            min_y = j;
          }
        }
      }
    }

    if (min_dist != INF)
    {
      cnt += min_dist;
      sea[min_x][min_y] = 0;
      shark_x = min_x;
      shark_y = min_y;
      eat_fish++;
      if (eat_fish == shark_size)
      {
        shark_size++;
        eat_fish = 0;
      }
    }
    else
    {
      break;
    }
  }
  cout << cnt << '\n';
}