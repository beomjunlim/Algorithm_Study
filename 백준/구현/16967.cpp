#include <iostream>
using namespace std;

int h, w, x, y;
int a[301][301];
int b[602][602];

void madeA()
{
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < w; j++)
    {
      a[i][j] = b[i][j];
    }
  }
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < h; j++)
    {
      a[j][i] = b[j][i];
    }
  }

  for (int i = x; i < h; i++)
  {
    for (int j = y; j < w; j++)
    {
      if (a[i][j] == 0)
      {
        a[i][j] = (b[i][j] - a[i - x][j - y]);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w >> x >> y;

  for (int i = 0; i < h + x; i++)
  {
    for (int j = 0; j < w + y; j++)
    {
      cin >> b[i][j];
    }
  }
  madeA();

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }
}