#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[101];
int cnt[101];
int answer = 0;
int max_num = 0;

void bfs(int start)
{
  queue<int> q;
  q.push(start);
  cnt[start] = 1;

  while (!q.empty())
  {
    int n = q.front();
    q.pop();

    for (int i = 0; i < arr[n].size(); i++)
    {
      int next = arr[n][i];
      if (cnt[next] == 0)
      {
        cnt[next] = cnt[n] + 1;
        q.push(next);
      }
    }
  }
}

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    int n, start;
    cin >> n >> start;

    for (int i = 0; i < n / 2; i++)
    {
      int a, b;
      cin >> a >> b;
      arr[a].push_back(b);
    }

    bfs(start);

    answer = 0;

    for (int i = 1; i < 101; i++)
    {
      if (cnt[i] >= cnt[answer])
      {
        answer = max(answer, i);
      }
    }

    cout << "#" << t << " " << answer << '\n';
  }
}