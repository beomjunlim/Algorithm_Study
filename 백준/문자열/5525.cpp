#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  int n, s;

  cin >> n >> s;
  cin >> str;

  int ans = 0;

  for (int i = 0; i <= (s - (2 * n + 1)); i++)
  {
    if (str[i] == 'I')
    {
      int cnt = 0;
      while (str[i + 1] == 'O' && str[i + 2] == 'I')
      {
        cnt++;
        if (cnt == n)
        {
          ans++;
          cnt--;
        }
        i += 2;
      }
    }
  }
  cout << ans << '\n';
}