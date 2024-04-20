#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int arr[3];
  cin >> n;

  int maxDp[3];
  int minDp[3];
  cin >> maxDp[0] >> maxDp[1] >> maxDp[2];

  minDp[0] = maxDp[0];
  minDp[1] = maxDp[1];
  minDp[2] = maxDp[2];

  for (int i = 1; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    arr[0] = maxDp[0];
    arr[1] = maxDp[1];
    arr[2] = maxDp[2];

    maxDp[0] = max(arr[0], arr[1]) + a;
    maxDp[1] = max(arr[0], max(arr[1], arr[2])) + b;
    maxDp[2] = max(arr[1], arr[2]) + c;

    arr[0] = minDp[0];
    arr[1] = minDp[1];
    arr[2] = minDp[2];

    minDp[0] = min(arr[0], arr[1]) + a;
    minDp[1] = min(arr[0], min(arr[1], arr[2])) + b;
    minDp[2] = min(arr[1], arr[2]) + c;
  }

  cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << " " << min(minDp[0], min(minDp[1], minDp[2])) << '\n';
}