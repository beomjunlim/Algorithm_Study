#include <iostream>
using namespace std;

int r, c;
pair<int, int> top;
pair<int, int> bottom;
int map[51][51];
int temp[51][51];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 < x && x <= r && 0 < y && y <= c;
}

void dust()
{

  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      if (map[i][j] != 0 && map[i][j] != -1)
      {
        int sum = map[i][j];
        int num = map[i][j] / 5;
        for (int k = 0; k < 4; k++)
        {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (InRange(nx, ny) && map[nx][ny] != -1)
          {
            temp[nx][ny] += num;
            sum -= num;
          }
        }
        temp[i][j] += sum;
      }
    }
  }

  temp[top.first][top.second] = -1;
  temp[bottom.first][bottom.second] = -1;
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      map[i][j] = temp[i][j];
      temp[i][j] = 0;
    }
  }
}

void clean()
{
  // top
  for (int i = top.first - 1; i > 1; i--)
  {
    map[i][1] = map[i - 1][1];
  }
  for (int i = 1; i < c; i++)
  {
    map[1][i] = map[1][i + 1];
  }

  for (int i = 1; i < top.first; i++)
  {
    map[i][c] = map[i + 1][c];
  }

  for (int i = c; i > 2; i--)
  {
    map[top.first][i] = map[top.first][i - 1];
  }
  map[top.first][2] = 0;

  // bottom
  for (int i = bottom.first + 1; i < r; i++)
  {
    map[i][1] = map[i + 1][1];
  }

  for (int i = 1; i < c; i++)
  {
    map[r][i] = map[r][i + 1];
  }

  for (int i = r; i > bottom.first; i--)
  {
    map[i][c] = map[i - 1][c];
  }

  for (int i = c; i > 2; i--)
  {
    map[bottom.first][i] = map[bottom.first][i - 1];
  }
  map[bottom.first][2] = 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  bool sw = false;
  int t;
  cin >> r >> c >> t;

  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      cin >> map[i][j];
      if (!sw && map[i][j] == -1)
      {
        top.first = i;
        top.second = j;
        bottom.first = i + 1;
        bottom.second = j;
        temp[i][j] = -1;
        temp[i + 1][j] = -1;
        sw = true;
      }
    }
  }

  while (t > 0)
  {
    dust();
    clean();
    t--;
  }

  int answer = 0;

  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      if (map[i][j] != -1)
      {
        answer += map[i][j];
      }
    }
  }
  cout << answer << '\n';
}