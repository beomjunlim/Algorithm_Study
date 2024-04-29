#include <iostream>
using namespace std;

int arr[50][50];

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%1d", &arr[i][j]);
        if (i < n / 2)
        {
          if (n / 2 - i <= j && j <= n / 2 + i)
            ans += arr[i][j];
        }
        else if (i > n / 2)
        {
          if ((n / 2 - (n - i) + 1) <= j && j <= (n / 2 + (n - i) - 1))
            ans += arr[i][j];
        }
        else
        {
          ans += arr[i][j];
        }
      }
    }
    cout << "#" << k << " " << ans << '\n';
  }
}