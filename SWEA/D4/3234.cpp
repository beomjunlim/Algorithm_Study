#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans;
int sum;
int arr[10];
bool visited[10];

int factorial(int num)
{
  if (num <= 1)
    return 1;
  else
    return num * factorial(num - 1);
}

void backtracking(int num, int left, int right)
{
  if (num == n)
  {
    ans++;
    return;
  }

  if (sum - left <= left)
  {
    ans += (pow(2, n - num) * factorial(n - num));
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      backtracking(num + 1, left + arr[i], right);
      if (left >= right + arr[i])
        backtracking(num + 1, left, right + arr[i]);
      visited[i] = false;
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    ans = 0;
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }

    backtracking(0, 0, 0);
    cout << "#" << k << " " << ans << '\n';
  }
}