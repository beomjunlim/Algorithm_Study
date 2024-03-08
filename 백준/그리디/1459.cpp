#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long x, y, w, s;
  cin >> x >> y >> w >> s;

  long long ans = 0;

  if (2 * w > s)
  {
    if (s > w)
    {
      ans = min(x, y) * s + abs(x - y) * w;
    }
    else
    {
      if ((x + y) % 2 != 0)
        ans = (max(x, y) - 1) * s + w;
      else
        ans = max(x, y) * s;
    }
  }
  else
  {
    ans = (x + y) * w;
  }

  cout << ans << '\n';
}