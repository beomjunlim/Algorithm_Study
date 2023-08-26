#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main()
{
  string s;
  cin >> s;
  int x = 0, y = 0;
  int dir_num = 0;
  int sum = 0;
  bool sw = false;
  for (int i = 0; i < s.length(); i++)
  {
    sum += 1;
    if (s[i] == 'F')
    {
      x = x + dx[dir_num];
      y = y + dy[dir_num];
      if (x == 0 && y == 0)
      {
        sw = true;
        break;
      }
    }
    if (s[i] == 'R')
    {
      dir_num = (dir_num + 1) % 4;
    }
    if (s[i] == 'L')
    {
      dir_num = (dir_num + 3) % 4;
    }
  }

  if (sw)
    cout << sum << '\n';
  else
    cout << "-1" << '\n';
  return 0;
}
