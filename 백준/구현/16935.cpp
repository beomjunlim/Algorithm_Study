#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int arr[101][101];
int temp[101][101];

void one()
{
  for (int i = 1; i <= n / 2; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      swap(arr[i][j], arr[n - i + 1][j]);
    }
  }
}

void two()
{
  for (int i = 1; i <= m / 2; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      swap(arr[j][i], arr[j][m - i + 1]);
    }
  }
}

void three()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      temp[j][n - i + 1] = arr[i][j];
    }
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      arr[i][j] = temp[i][j];
    }
  }
}

void four()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      temp[m - j + 1][i] = arr[i][j];
    }
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      arr[i][j] = temp[i][j];
    }
  }
}

void five()
{
  for (int i = 1; i <= n / 2; i++)
  {
    for (int j = 1; j <= m / 2; j++)
    {
      temp[i][j] = arr[i + n / 2][j];
      temp[i + n / 2][j] = arr[i + n / 2][j + m / 2];
      temp[i][j + m / 2] = arr[i][j];
      temp[i + n / 2][j + m / 2] = arr[i][j + m / 2];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      arr[i][j] = temp[i][j];
    }
  }
}

void six()
{
  for (int i = 1; i <= n / 2; i++)
  {
    for (int j = 1; j <= m / 2; j++)
    {
      temp[i][j] = arr[i][j + m / 2];
      temp[i + n / 2][j] = arr[i][j];
      temp[i][j + m / 2] = arr[i + n / 2][j + m / 2];
      temp[i + n / 2][j + m / 2] = arr[i + n / 2][j];
    }
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

  for (int i = 0; i < r; i++)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      one();
    }
    if (a == 2)
    {
      two();
    }
    if (a == 3)
    {
      three();
      swap(n, m);
    }
    if (a == 4)
    {
      four();
      swap(n, m);
    }
    if (a == 5)
    {
      five();
    }
    if (a == 6)
    {
      six();
    }
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