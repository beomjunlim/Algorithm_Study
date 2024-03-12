#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[26];
char ans[16];

void myfunction(int cnt, int idx, int mo, int ja)
{
  if (cnt == l)
  {
    if (mo >= 1 && ja >= 2)
    {
      for (int i = 0; i < l; i++)
      {
        cout << ans[i];
      }
      cout << '\n';
    }
    return;
  }

  for (int i = idx; i < c; i++)
  {
    ans[cnt] = arr[i];
    if (ans[cnt] == 'a' || ans[cnt] == 'e' || ans[cnt] == 'i' || ans[cnt] == 'o' || ans[cnt] == 'u')
      myfunction(cnt + 1, i + 1, mo + 1, ja);
    else
      myfunction(cnt + 1, i + 1, mo, ja + 1);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> l >> c;

  for (int i = 0; i < c; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + c);
  myfunction(0, 0, 0, 0);
}