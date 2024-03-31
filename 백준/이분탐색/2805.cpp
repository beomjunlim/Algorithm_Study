#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int n, m;
int ans = 0;

void myFunction(int x, int y)
{
  int start = x;
  int end = y;

  while (start <= end)
  {
    int mid = (start + end) / 2;
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] > mid)
        cnt += (arr[i] - mid);
    }
    if (cnt >= m)
    {
      ans = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  myFunction(1, arr[n - 1]);
  cout << ans << '\n';
}
