#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[100][100];
int dir; // up 0 right 1 left 2

bool InRange(int x, int y)
{
  return 0 <= x && x < 100 && 0 <= y && y < 100;
}

int bfs(int start)
{
  queue<pair<int, int>> q;
  q.push(make_pair(99, start));
  dir = 0;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (x == 0 && arr[x][y] == 1)
    {
      return y;
    }

    if (dir == 0)
    {
      if (InRange(x, y - 1) && arr[x][y - 1] == 1)
      {
        dir = 2;
        q.push(make_pair(x, y - 1));
      }
      else if (InRange(x, y + 1) && arr[x][y + 1] == 1)
      {
        dir = 1;
        q.push(make_pair(x, y + 1));
      }
      else if (InRange(x - 1, y) && arr[x - 1][y] == 1)
      {
        q.push(make_pair(x - 1, y));
      }
    }

    else if (dir == 1)
    {
      if (InRange(x, y + 1) && arr[x][y + 1] == 1)
      {
        q.push(make_pair(x, y + 1));
      }
      else if ((!InRange(x, y + 1) && InRange(x - 1, y)) || (InRange(x - 1, y) && InRange(x, y + 1) && arr[x][y + 1] == 0))
      {
        dir = 0;
        q.push(make_pair(x - 1, y));
      }
    }

    else if (dir == 2)
    {
      if (InRange(x, y - 1) && arr[x][y - 1] == 1)
      {
        q.push(make_pair(x, y - 1));
      }
      else if ((!InRange(x, y - 1) && InRange(x - 1, y)) || (InRange(x - 1, y) && InRange(x, y - 1) && arr[x][y - 1] == 0))
      {
        dir = 0;
        q.push(make_pair(x - 1, y));
      }
    }
  }
  return -1;
}

int main()
{
  for (int k = 1; k <= 10; k++)
  {
    int destination;
    int t;
    cin >> t;
    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 100; j++)
      {
        cin >> arr[i][j];
        if (i == 99 && arr[i][j] == 2)
          destination = j;
      }
    }

    cout << "#" << t << " " << bfs(destination) << '\n';
  }
}