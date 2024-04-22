#include <iostream>
#include <queue>
using namespace std;

int n;
long long b;
long long A[5][5];
long long ans[5][5];
long long tmp[5][5];

void multi_matrix(long long x[5][5], long long y[5][5])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      long long sum = 0;
      for (int k = 0; k < n; k++)
      {
        sum += x[i][k] * y[k][j];
      }
      tmp[i][j] = sum % 1000;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      x[i][j] = tmp[i][j];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> b;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> A[i][j];
    }
    ans[i][i] = 1;
  }

  while (b > 0)
  {
    if (b % 2 != 0)
    {
      multi_matrix(ans, A);
    }
    multi_matrix(A, A);
    b /= 2;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
}