#include <iostream>
#include <climits>
using namespace std;

#define MAX 11
int n;
int ans = INT_MAX;
int arr[MAX][MAX];
bool visited[MAX];
int start;

void myfunction(int visit_city, int cnt, int sum)
{
  if (cnt == n)
  {
    if (arr[visit_city][start] > 0)
      ans = min(ans, sum + arr[visit_city][start]);
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i] && arr[visit_city][i] != 0)
    {
      visited[i] = true;
      myfunction(i, cnt + 1, sum + arr[visit_city][i]);
      visited[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int answer = INT_MAX;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    start = i;
    visited[i] = true;
    myfunction(i, 1, 0);
    visited[i] = false;
  }

  cout << ans << '\n';
}