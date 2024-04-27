#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    cin >> n;
    long long ans = 0;
    vector<int> day(n);

    for (int i = 0; i < n; i++)
    {
      cin >> day[i];
    }

    int price = day[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
      if (day[i] < price)
      {
        ans += (price - day[i]);
      }
      else
      {
        price = day[i];
      }
    }
    cout << k << " " << ans << '\n';
  }
}