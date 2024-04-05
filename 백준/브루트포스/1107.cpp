#include <iostream>
#include <cmath>
using namespace std;

int numbers[10];

bool setNumbers(int n)
{
  string str = to_string(n);

  for (int i = 0; i < str.length(); i++)
  {
    if (numbers[str[i] - '0'] == 1)
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  int ch = 100;

  for (int i = 0; i < m; i++)
  {
    int a;
    cin >> a;
    numbers[a] = 1;
  }

  int ans = abs(n - ch);

  for (int i = 0; i <= 1000000; i++)
  {
    if (setNumbers(i))
    {
      int cnt = abs(n - i) + to_string(i).length();
      ans = min(ans, cnt);
    }
  }
  cout << ans << '\n';
}