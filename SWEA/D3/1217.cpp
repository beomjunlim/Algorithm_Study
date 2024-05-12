#include <iostream>
using namespace std;

int pow(int n, int num)
{
  if (num == 1)
  {
    return n;
  }
  return n * pow(n, num - 1);
}

int main()
{
  for (int i = 1; i <= 10; i++)
  {
    int t;
    cin >> t;

    int n, m;
    cin >> n >> m;

    int ans = pow(n, m);
    cout << "#" << t << " " << ans << '\n';
  }
}