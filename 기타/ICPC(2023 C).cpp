#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  string s;
  getline(cin, s);

  float h_n = 0;
  float s_n = 0;
  float ans = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'H' || s[i] == 'P' || s[i] == 'Y')
      h_n += 1;
    if (s[i] == 'S' || s[i] == 'D')
      s_n += 1;
    if (s[i] == 'A')
    {
      h_n += 1;
      s_n += 1;
    }
  }
  cout << h_n << " " << s_n << '\n';
  if (h_n == 0 && s_n == 0)
    ans = 50;
  else
    ans = (h_n / (h_n + s_n));

  cout << fixed << setprecision(2) << ans << '\n';
}
