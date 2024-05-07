#include <iostream>
#include <cstring>
#include <map>
using namespace std;

bool sw = false;
map<int, int> arrA;
map<int, int> arrB;
bool visited[100];

void dfs(int start)
{
  visited[start] = true;

  if (start == 99)
  {
    sw = true;
    return;
  }

  if (arrA.find(start) != arrA.end() && !visited[arrA.find(start)->second])
  {
    dfs(arrA.find(start)->second);
  }
  if (arrB.find(start) != arrB.end() && !visited[arrB.find(start)->second])
  {
    dfs(arrB.find(start)->second);
  }
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    memset(visited, false, sizeof(visited));
    sw = false;
    int k, n;
    cin >> k >> n;

    arrA.clear();
    arrB.clear();

    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;
      if (arrA.find(a) != arrA.end())
      {
        arrB[a] = b;
      }
      else
      {
        arrA[a] = b;
      }
    }

    dfs(0);

    if (sw)
      cout << "#" << t << " " << 1 << '\n';
    else
      cout << "#" << t << " " << 0 << '\n';
  }
}