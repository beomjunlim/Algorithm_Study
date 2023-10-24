#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
char ch[MAX];

int main()
{
  int n;
  cin >> n;
  int x = 0, y = 0;
  int sum = 0;
  bool sw = false;
  for (int i = 0; i < n; i++)
  {
    cin >> ch[i] >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    char c;
    int a;
    c = ch[i];
    a = arr[i];
    if (c == 'N')
    {
      for (int j = 0; j < a; j++)
      {
        y += 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'S')
    {
      for (int j = 0; j < a; j++)
      {
        y -= 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'W')
    {
      for (int j = 0; j < a; j++)
      {
        x -= 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (c == 'E')
    {
      for (int j = 0; j < a; j++)
      {
        x += 1;
        sum += 1;
        if (x == 0 && y == 0)
        {
          sw = true;
          break;
        }
      }
    }
    if (sw)
      break;
  }
  if (sw)
    cout << sum << '\n';
  else
    cout << "-1" << '\n';
  return 0;
}
