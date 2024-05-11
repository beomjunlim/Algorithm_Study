#include <iostream>
using namespace std;

int arr[301][301];

int main()
{
  int t;
  cin >> t;

  arr[0][1] = 1;

  for (int i = 1; i <= 300; i++)
  {
    arr[i][1] = arr[i - 1][1] + i - 1;
    for (int j = 2; j <= 300; j++)
    {
      arr[i][j] = arr[i][j - 1] + i + j - 1;
    }
  }

  for (int k = 1; k <= t; k++)
  {
    int p, q;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    cin >> p >> q;

    for (int i = 1; i <= 300; i++)
    {
      for (int j = 1; j <= 300; j++)
      {
        if (arr[i][j] == p)
        {
          x1 = i;
          y1 = j;
        }
        if (arr[i][j] == q)
        {
          x2 = i;
          y2 = j;
        }
      }
    }
    cout << "#" << k << " " << arr[x1 + x2][y1 + y2] << '\n';
  }
}