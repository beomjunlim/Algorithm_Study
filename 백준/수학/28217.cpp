#include <iostream>
using namespace std;

#define MAX 10
int a[MAX][MAX];
int b[MAX][MAX];
int temp[MAX][MAX];
int temp2[MAX][MAX];
int n;

int cmp()
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (temp[i][j] != b[i][j])
        cnt++;
    }
  }
  return cnt;
}

void copyArr()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      temp[i][j] = a[i][j];
    }
  }
}

void symmetry()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      temp[i][j] = a[i][i - j];
    }
  }
}

void right()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j >= i; j--)
    {
      temp[j][i] = a[n - 1 - i][j - i];
    }
  }
}

void right_symmetry()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j >= i; j--)
    {
      temp2[j][i] = a[n - 1 - i][j - i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      temp[i][j] = temp2[i][i - j];
    }
  }
}

void left()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      temp[n - 1 - i][j] = a[j + i][i];
    }
  }
}

void left_symmetry()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      temp2[n - 1 - i][j] = a[j + i][i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      temp[i][j] = temp2[i][i - j];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> b[i][j];
    }
  }

  copyArr();
  int ans = cmp();

  symmetry();
  ans = min(ans, cmp());

  right();
  ans = min(ans, cmp());

  left();
  ans = min(ans, cmp());

  right_symmetry();
  ans = min(ans, cmp());

  left_symmetry();
  ans = min(ans, cmp());

  cout << ans << '\n';
}