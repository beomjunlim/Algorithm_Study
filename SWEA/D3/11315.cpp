#include <iostream>
using namespace std;

bool sw = false;
int n;
char arr[21][21];
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y, int dir, int num)
{

  if (num >= 5)
  {
    sw = true;
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (InRange(nx, ny) && arr[nx][ny] == 'o')
    {
      if (num != 1)
      {
        if (dir == i)
          dfs(nx, ny, i, num + 1);
      }
      else
      {
        dfs(nx, ny, i, num + 1);
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    sw = false;
    string ans = "NO";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i][j] == 'o')
        {
          dfs(i, j, 0, 1);
        }

        if (sw)
          break;
      }
    }
    if (sw)
      ans = "YES";

    cout << "#" << k << " " << ans << '\n';
  }
}