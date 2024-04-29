#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;
int answer = 0;
int arr[4][4];
int str[7];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void backTracking(int x, int y, int cnt)
{
  if (cnt == 7)
  {
    string ans = "";
    for (int i = 0; i < 7; i++)
    {
      ans += to_string(str[i]);
    }

    if (s.find(ans) == s.end())
    {
      s.insert(ans);
      answer++;
    }
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (InRange(nx, ny))
    {
      str[cnt] = arr[nx][ny];
      backTracking(nx, ny, cnt + 1);
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    s.clear();
    answer = 0;
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        str[0] = arr[i][j];
        backTracking(i, j, 1);
      }
    }
    cout << "#" << k << " " << answer << '\n';
  }
}