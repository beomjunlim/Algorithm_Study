#include <iostream>
using namespace std;

int map[16][16];
bool visited[16][16];
bool sw = false;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < 16 && 0 <= y && y < 16;
}

void dfs(int x, int y)
{
  visited[x][y] = true;

  if (map[x][y] == 3)
  {
    sw = true;
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (InRange(nx, ny) && map[nx][ny] != 1 && !visited[nx][ny])
    {
      dfs(nx, ny);
    }
  }
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    int num;
    int ans = 0;
    sw = false;
    pair<int, int> start;
    cin >> num;

    for (int i = 0; i < 16; i++)
    {
      for (int j = 0; j < 16; j++)
      {
        visited[i][j] = false;
      }
    }

    for (int i = 0; i < 16; i++)
    {
      for (int j = 0; j < 16; j++)
      {
        scanf("%1d", &map[i][j]);
        if (map[i][j] == 2)
        {
          start.first = i;
          start.second = j;
        }
      }
    }

    dfs(start.first, start.second);

    if (sw)
      ans = 1;

    cout << "#" << t << " " << ans << '\n';
  }
}