#include <iostream>
using namespace std;

int n;
int answer = 0;
int map[17][17];

bool InRange(int x, int y)
{
  return 0 < x && x <= n && 0 < y && y <= n;
}

bool canGo(int x, int y)
{
  if (InRange(x, y) && map[x][y] == 0)
  {
    return true;
  }
  return false;
}

void pipeFunction(int x, int y, int direction)
{
  if (x == n && y == n)
  {
    answer++;
    return;
  }

  if (direction == 0)
  { // 가로
    if (canGo(x, y + 1))
    {
      pipeFunction(x, y + 1, 0);
    }
    if (canGo(x, y + 1) && canGo(x + 1, y) && canGo(x + 1, y + 1))
    {
      pipeFunction(x + 1, y + 1, 1);
    }
  }
  else if (direction == 1)
  { // 대각선
    if (canGo(x, y + 1) && canGo(x + 1, y) && canGo(x + 1, y + 1))
    {
      pipeFunction(x + 1, y + 1, 1);
    }
    if (canGo(x, y + 1))
    {
      pipeFunction(x, y + 1, 0);
    }
    if (canGo(x + 1, y))
    {
      pipeFunction(x + 1, y, 2);
    }
  }
  else
  { // 세로
    if (canGo(x + 1, y))
    {
      pipeFunction(x + 1, y, 2);
    }
    if (canGo(x, y + 1) && canGo(x + 1, y) && canGo(x + 1, y + 1))
    {
      pipeFunction(x + 1, y + 1, 1);
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
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
    }
  }

  pipeFunction(1, 2, 0);
  cout << answer << '\n';
}