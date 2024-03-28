#include <iostream>
using namespace std;

int n;
int arr[129][129];
int ans[2];

void myFunction(int x, int y, int num)
{
  bool sw = true;
  for (int i = x; i < x + num; i++)
  {
    for (int j = y; j < y + num; j++)
    {
      if (arr[x][y] != arr[i][j])
      {
        sw = false;
        break;
      }
    }
  }
  if (sw)
  {
    ans[arr[x][y]]++;
  }
  else
  {
    myFunction(x, y, num / 2);
    myFunction(x + num / 2, y + num / 2, num / 2);
    myFunction(x + num / 2, y, num / 2);
    myFunction(x, y + num / 2, num / 2);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }
  myFunction(1, 1, n);
  for (int i = 0; i < 2; i++)
  {
    cout << ans[i] << '\n';
  }
}