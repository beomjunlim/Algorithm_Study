#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int cnt = 0;
  cin >> n;

  if (n < 100)
  {
    cout << n << '\n';
  }
  else
  {
    cnt = 99;
    for (int i = 100; i <= n; i++)
    {
      int one = i / 100;
      int two = (i / 10) % 10;
      int thr = i % 10;

      if ((one - two) == (two - thr))
      {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
}