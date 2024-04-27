#include <iostream>
using namespace std;

int n;
int arr[10][10];

int snail(int idx, int num)
{
  for (int i = idx; i < n - idx; i++)
  {
    arr[idx][i] = num;
    num++;
  }

  for (int i = idx + 1; i < n - idx; i++)
  {
    arr[i][n - idx - 1] = num;
    num++;
  }

  for (int i = n - idx - 2; i >= idx; i--)
  {
    arr[n - idx - 1][i] = num;
    num++;
  }

  for (int i = n - idx - 2; i > idx; i--)
  {
    arr[i][idx] = num;
    num++;
  }
  return num;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    cin >> n;
    int num = 1;
    int idx = 0;
    for (int i = n; i > 0; i -= 2)
    {
      num = snail(idx, num);
      idx++;
    }
    cout << "#" << k << '\n';

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << arr[i][j] << " ";
      }
      cout << '\n';
    }
  }
}