#include <iostream>
using namespace std;

int ans;
char arr[8][8];

void cnt_low(int column, int start, int end)
{
  bool sw = true;
  while (start < end)
  {
    if (arr[start][column] != arr[end][column])
    {
      sw = false;
      break;
    }
    start++;
    end--;
  }

  if (sw)
    ans++;
}

void cnt_column(int row, int start, int end)
{
  bool sw = true;

  while (start < end)
  {
    if (arr[row][start] != arr[row][end])
    {
      sw = false;
      break;
    }
    start++;
    end--;
  }

  if (sw)
    ans++;
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    int n;
    ans = 0;
    cin >> n;
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        cin >> arr[i][j];
      }
    }

    for (int k = 0; k < 8; k++)
    {
      for (int i = 0; i <= 8 - n; i++)
      {
        int start_idx = i;
        int end_idx = n + i - 1;
        cnt_column(k, start_idx, end_idx);
        cnt_low(k, start_idx, end_idx);
      }
    }
    cout << "#" << t << " " << ans << '\n';
  }
}