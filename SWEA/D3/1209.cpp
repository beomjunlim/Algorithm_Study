#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int arr[100][100];

void cnt_low(int column)
{
  int temp = 0;

  for (int i = 0; i < 100; i++)
  {
    temp += arr[i][column];
  }

  ans = max(ans, temp);
}

void cnt_column(int low)
{
  int temp = 0;

  for (int i = 0; i < 100; i++)
  {
    temp += arr[low][i];
  }

  ans = max(ans, temp);
}

void cnt_diagonal()
{
  int temp = 0;

  for (int i = 0; i < 100; i++)
  {
    temp += arr[i][i];
  }

  ans = max(ans, temp);

  temp = 0;

  for (int i = 0; i < 100; i++)
  {
    temp += arr[99 - i][i];
  }

  ans = max(ans, temp);
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    int num;
    ans = 0;
    cin >> num;

    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 100; j++)
      {
        cin >> arr[i][j];
      }
    }

    cnt_diagonal();

    for (int i = 0; i < 100; i++)
    {
      cnt_low(i);
      cnt_column(i);
    }

    cout << "#" << t << " " << ans << '\n';
  }
}