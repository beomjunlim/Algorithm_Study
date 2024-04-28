#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans;
int arr[11];
bool visited[11];

bool check(int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    if (arr[i] == col || abs(i - row) == abs(arr[i] - col))
      return false;
  }
  return true;
}

void backtracking(int row)
{
  if (row == n)
  {
    ans++;
    return;
  }

  for (int col = 0; col < n; col++)
  {
    if (visited[col])
      continue;
    if (check(row, col))
    {
      visited[col] = true;
      arr[row] = col;
      backtracking(row + 1);
      visited[col] = false;
      arr[row] = 0;
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
      visited[i] = false;
      arr[i] = 0;
    }
    backtracking(0);

    cout << "#" << k << " " << ans << '\n';
  }
}