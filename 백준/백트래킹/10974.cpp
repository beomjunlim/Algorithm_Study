#include <iostream>
using namespace std;

#define MAX 9
int n;
int ans[MAX];
bool visited[MAX];

void myfunction(int cnt)
{
  if (cnt == n)
  {
    for (int i = 0; i < n; i++)
    {
      cout << ans[i] << " ";
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      ans[cnt] = i;
      myfunction(cnt + 1);
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
  myfunction(0);
}