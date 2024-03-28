#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, num;
  cin >> n;

  int bit = 0;

  while (n > 0)
  {
    string str;
    cin >> str;

    if (str == "add")
    {
      cin >> num;
      num -= 1;
      bit |= (1 << num);
    }

    if (str == "remove")
    {
      cin >> num;
      num -= 1;
      bit &= ~(1 << num);
    }

    if (str == "check")
    {
      cin >> num;
      num -= 1;
      if (bit & (1 << num))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }

    if (str == "toggle")
    {
      cin >> num;
      num -= 1;
      bit ^= (1 << num);
    }

    if (str == "all")
    {
      bit = (1 << 20) - 1;
    }

    if (str == "empty")
    {
      bit = 0;
    }
    n--;
  }
}