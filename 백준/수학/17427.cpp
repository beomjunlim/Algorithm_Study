#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += (n / i) * i;
  }
  cout << ans << '\n';
}
