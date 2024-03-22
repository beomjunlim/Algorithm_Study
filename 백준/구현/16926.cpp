#include <iostream>
using namespace std;

int n, m, r;
int arr[301][301];
int temp[301][301];

void rotation()
{
  int start = 1;
  int low = n;
  int column = m;
  while (start <= low && start <= column)
  {

    for (int i = start + 1; i <= low; i++)
    {
      temp[i][start] = arr[i - 1][start];
      temp[i - 1][column] = arr[i][column];
    }

    for (int i = start + 1; i <= column; i++)
    {
      temp[low][i] = arr[low][i - 1];
      temp[start][i - 1] = arr[start][i];
    }
    start++;
    low--;
    column--;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      arr[i][j] = temp[i][j];
    }
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

  for (int i = 1; i <= r; i++)
  {
    rotation();
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