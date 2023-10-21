#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int ans = 0;

  int len = to_string(n).length();

  if (len > 1)
  {
    for (int i = 2; i <= len; i++)
    {
      ans += 9 * pow(10, i / 2 - 1);
    }
  }

  for (int i = pow(10, len - 1); i <= n; i++)
  {
    bool sw = true;
    string s = to_string(i);
    int m = s.length();
    for (int j = 0; j < m / 2; j++)
    {
      if (s[j] != s[m - j - 1])
      {
        sw = false;
        break;
      }
    }
    if (sw)
      ans += 1;
  }
  cout << ans << '\n';
}
