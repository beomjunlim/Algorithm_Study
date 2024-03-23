#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int arr[301][301];
int temp[301][301];

void rotation(int a, int low, int column)
{
  int start = a;
  int len = 2 * (low - a + 1 + column - a + 1) - 4;

  for (int k = 0; k < r % len; k++)
  {
    int temp = arr[start][start];
    for (int i = start; i < column; i++)
    {
      arr[start][i] = arr[start][i + 1];
    }

    for (int i = start; i < low; i++)
    {
      arr[i][column] = arr[i + 1][column];
    }

    for (int i = column; i > start; i--)
    {
      arr[low][i] = arr[low][i - 1];
    }

    for (int i = low; i > start; i--)
    {
      arr[i][start] = arr[i - 1][start];
    }
    arr[start + 1][start] = temp;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
    }
  }

  int cnt = min(n, m) / 2;
  int low = n;
  int column = m;

  for (int i = 1; i <= cnt; i++)
  {
    rotation(i, low, column);
    low--;
    column--;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}