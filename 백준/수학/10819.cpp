#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 8
int n;
int arr[MAX];
bool visited[MAX];
int ans[MAX];
int sum = 0;

void myFunction(int cnt)
{
  if (cnt == n)
  {
    int num = 0;
    for (int i = 0; i < n - 1; i++)
    {
      num += abs(ans[i] - ans[i + 1]);
    }
    sum = max(sum, num);
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      ans[cnt] = arr[i];
      myFunction(cnt + 1);
      visited[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  myFunction(0);
  cout << sum << '\n';
}