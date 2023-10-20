#include <iostream>
using namespace std;

#define MAX 1000

int arr[MAX][MAX];
bool visited[MAX][MAX];
int m, n;
bool sw = false;

int dx[] = {0, 1, 0}, dy[] = {-1, 0, 1};

void Initialize()
{
  for (int i = 0; i < m - 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      visited[i][j] = false;
    }
  }
}

bool InRange(int r, int c)
{
  return 0 <= r && r < m && 0 <= c && c < n;
}

bool CanGo(int r, int c)
{
  if (InRange(r, c) && arr[r][c] == 0 && !visited[r][c])
    return true;
  else
    return false;
}

void DFS(int r, int c)
{
  for (int i = 0; i < 3; i++)
  {
    int n_r = r + dx[i];
    int n_c = c + dy[i];
    if (CanGo(n_r, n_c))
    {
      visited[n_r][n_c] = true;
      if (n_r == m - 1)
        sw = true;
      DFS(n_r, n_c);
    }
  }
}

int main()
{

  cin >> m >> n;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    DFS(0, i);
    if (sw)
    {
      cout << "YES";
      break;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (visited[m - 1][i])
    {
      sw = true;
      break;
    }
  }
  if (!sw)
    cout << "NO";
}
