#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main()
{
  int l;
  cin >> l;

  for (int t = 1; t <= l; t++)
  {
    int n, m, k;
    bool sw = true;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    sort(arr, arr + n);

    int time;
    int fish = 0;

    for (int i = 0; i < n; i++)
    {
      fish = k * (arr[i] / m);
      fish -= (i + 1);
      if (fish < 0)
      {
        sw = false;
        break;
      }
    }

    string s = "Possible";
    if (!sw)
      s = "Impossible";

    cout << "#" << t << " " << s << '\n';
  }
}