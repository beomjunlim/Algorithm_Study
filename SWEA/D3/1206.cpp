#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int t = 1; t <= 10; t++)
  {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
      cin >> arr[i];
    }

    int ans = 0;

    for (int i = 2; i < num - 2; i++)
    {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i - 2] && arr[i] > arr[i + 1] && arr[i] > arr[i + 2])
      {
        int high = max(arr[i - 2], max(arr[i - 1], max(arr[i + 1], arr[i + 2])));
        ans += (arr[i] - high);
      }
    }

    cout << "#" << t << " " << ans << '\n';
  }
}