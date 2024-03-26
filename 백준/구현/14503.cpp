#include <iostream>
using namespace std;

int n, m;
int arr[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < m;
}

bool checkMove(int x, int y)
{
  if (InRange(x, y) && arr[x][y] == 0)
  {
    return true;
  }
  return false;
}

int clean(int r, int c, int d)
{
  int cnt = 0;
  bool t = true;
  while (t)
  {
    bool sw = false;

    if (!arr[r][c])
    {
      arr[r][c] = 2;
      cnt++;
    }

    for (int i = 0; i < 4; i++)
    {

      if (checkMove(r + dx[i], c + dy[i]))
      {
        sw = true;
      }
    }

    if (sw)
    {
      while (1)
      {
        d = (d + 3) % 4;
        int nr = r + dx[d];
        int nc = c + dy[d];

        if (!arr[nr][nc])
        {
          r = nr;
          c = nc;
          break;
        }
      }
    }
    else
    {
      r = r + dx[(d + 2) % 4];
      c = c + dy[(d + 2) % 4];
      if (!InRange(r, c) || arr[r][c] == 1)
        t = false;
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int r, c, d;
  cin >> n >> m;
  cin >> r >> c >> d;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout << clean(r, c, d);
}