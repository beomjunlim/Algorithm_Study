#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
bool sw;
char arr[20][20];
bool visited[20][20][4][16];
int dx[] = {0, 1, 0, -1}; // right down left up
int dy[] = {1, 0, -1, 0};

bool bfs()
{
  queue<pair<int, pair<int, pair<int, int>>>> q;
  q.push(make_pair(0, make_pair(0, make_pair(0, 0)))); // dir memory x y
  visited[0][0][0][0] = true;

  while (!q.empty())
  {
    int x = q.front().second.second.first;
    int y = q.front().second.second.second;
    int direction = q.front().first;
    int mem = q.front().second.first;
    q.pop();

    char c = arr[x][y];

    if (c == '?')
    {
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 좌표가 미로 범위 내에 있는지 확인
        if (nx < 0)
          nx = r - 1;
        if (nx >= r)
          nx = 0;
        if (ny < 0)
          ny = c - 1;
        if (ny >= c)
          ny = 0;

        if (!visited[nx][ny][i][mem])
        {
          visited[nx][ny][i][mem] = true;
          q.push(make_pair(i, make_pair(mem, make_pair(nx, ny)))); // dir memory x y
        }
      }
    }

    else
    {
      if (c - '0' < 10 && c - '0' >= 0)
        mem = c - '0';

      else if (c == '>')
        direction = 0;

      else if (c == 'v')
        direction = 1;

      else if (c == '<')
        direction = 2;

      else if (c == '^')
        direction = 3;

      else if (c == '_')
      {
        if (mem == 0)
          direction = 0;
        else
          direction = 2;
      }
      else if (c == '|')
      {
        if (mem == 0)
          direction = 1;
        else
          direction = 3;
      }
      else if (c == '@')
      {
        return true;
      }
      else if (c == '+')
      {
        if (mem == 15)
          mem = 0;
        else
          mem++;
      }
      else if (c == '-')
      {
        if (mem == 0)
          mem = 15;
        else
          mem--;
      }

      int nx = x + dx[direction];
      int ny = y + dy[direction];

      if (nx == -1)
        nx = r - 1;
      else if (nx == r)
        nx = 0;
      else if (ny == -1)
        ny = c - 1;
      else if (ny == c)
        ny = 0;

      if (!visited[nx][ny][direction][mem])
      {
        visited[nx][ny][direction][mem] = true;
        q.push(make_pair(direction, make_pair(mem, make_pair(nx, ny)))); // dir memory x y
      }
    }
  }
  return false;
}

int main()
{
  int k;
  cin >> k;

  for (int t = 1; t <= k; t++)
  {
    bool destination = false;
    sw = false;
    cin >> r >> c;

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        cin >> arr[i][j];
        if (arr[i][j] == '@')
          destination = true;
      }
    }

    if (destination)
      sw = bfs();

    string ans = "";

    if (sw)
      ans = "YES";
    else
      ans = "NO";

    cout << "#" << t << " " << ans << '\n';
  }
}
