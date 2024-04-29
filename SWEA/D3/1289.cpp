#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    string s;
    cin >> s;
    int ans = 0;
    bool flag = false;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1' && !flag)
      {
        ans++;
        flag = true;
      }
      else if (s[i] == '0' && flag)
      {
        ans++;
        flag = false;
      }
    }
    cout << "#" << k << " " << ans << '\n';
  }
}