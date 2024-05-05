#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
char arr[100][100];

void cnt_low(int column, int start, int length)
{
  bool sw = true;
  int start_idx = start;
  int end_idx = start + length - 1;

  while (start_idx < end_idx)
  {
    if (arr[start_idx][column] != arr[end_idx][column])
    {
      sw = false;
      return;
    }
    start_idx++;
    end_idx--;
  }

  if (sw)
    ans = max(ans, length);
}

void cnt_column(int low, int start, int length)
{
  bool sw = true;
  int start_idx = start;
  int end_idx = start + length - 1;

  while (start_idx < end_idx)
  {
    if (arr[low][start_idx] != arr[low][end_idx])
    {
      sw = false;
      return;
    }
    start_idx++;
    end_idx--;
  }

  if (sw)
    ans = max(ans, length);
}

int main()
{
  for (int l = 1; l <= 10; l++)
  {
    ans = 0;
    int t;
    cin >> t;

    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 100; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int k = 100; k > 1; k--)
    {
      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; j < 100 - k + 1; j++)
        {
          cnt_low(i, j, k);
          cnt_column(i, j, k);
        }
      }
    }

    cout << "#" << t << " " << ans << '\n';
  }
}