#include <iostream>
using namespace std;

int n;
int arr[1001];
int increase[1001];
int diminish[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    increase[i] = 1;
    diminish[i] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        increase[i] = max(increase[j] + 1, increase[i]);
      }
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (arr[i] > arr[j])
      {
        diminish[i] = max(diminish[j] + 1, diminish[i]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    int temp = increase[i] + diminish[i] - 1;
    ans = max(ans, temp);
  }

  cout << ans << "\n";
}