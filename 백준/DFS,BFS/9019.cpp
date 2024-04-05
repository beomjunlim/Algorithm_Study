#include <iostream>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;

int a, b;
bool visited[10000];

void bfs()
{
  queue<pair<int, string>> q;
  q.push(make_pair(a, ""));
  visited[a] = true;

  while (!q.empty())
  {
    int num = q.front().first;
    string ans = q.front().second;
    q.pop();

    if (num == b)
    {
      cout << ans << '\n';
      return;
    }

    int D = (num * 2) % 10000;
    if (!visited[D])
    {
      visited[D] = true;
      q.push(make_pair(D, ans + "D"));
    }

    int S = num - 1;

    if (num - 1 < 0)
      S = 9999;
    if (!visited[S])
    {
      visited[S] = true;
      q.push(make_pair(S, ans + "S"));
    }

    int L = (num % 1000) * 10 + (num / 1000);

    if (!visited[L])
    {
      visited[L] = true;
      q.push(make_pair(L, ans + "L"));
    }

    int R = (num / 10) + (num % 10) * 1000;

    if (!visited[R])
    {
      visited[R] = true;
      q.push(make_pair(R, ans + "R"));
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t > 0)
  {
    cin >> a >> b;
    memset(visited, 0, sizeof(visited));
    bfs();
    t--;
  }
}