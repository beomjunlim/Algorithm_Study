#include <iostream>
#include <algorithm>
using namespace std;

int num;
int ans;
int arr[100][100];

void cnt(int x)
{
  bool top_block = false;
  bool down_block = false;
  int top_idx = 0;
  int down_idx = num - 1;

  while (top_idx < num && down_idx >= 0)
  {
    if (!top_block)
    {
      if (arr[top_idx][x] == 2)
        arr[top_idx][x] = 0;
      else if (arr[top_idx][x] == 1)
        top_block = true;
      top_idx++;
    }

    if (!down_block)
    {
      if (arr[down_idx][x] == 1)
        arr[down_idx][x] = 0;
      else if (arr[down_idx][x] == 2)
        down_block = true;
      down_idx--;
    }

    if (top_block && down_block)
      break;
  }

  bool sw = false;

  for (int i = 0; i < num; i++)
  {
    if (arr[i][x] == 1 && !sw)
    {
      sw = true;
    }
    if (arr[i][x] == 2 && sw)
    {
      ans++;
      sw = false;
    }
  }
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    ans = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
      for (int j = 0; j < num; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < num; i++)
    {
      cnt(i);
    }
    cout << "#" << t << " " << ans << '\n';
  }
}