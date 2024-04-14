#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool visited[10];
int answer[10];
int arr[10];

void backtraking(int num)
{
  if (num == m + 1)
  {
    for (int i = 1; i <= m; i++)
    {
      cout << answer[i] << " ";
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (answer[num - 1] <= arr[i])
    {
      answer[num] = arr[i];
      backtraking(num + 1);
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
  backtraking(1);
}