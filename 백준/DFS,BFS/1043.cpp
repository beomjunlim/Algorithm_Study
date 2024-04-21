#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
bool know[51];
bool meet[51][51];
bool visited[51];
vector<int> party[51];
queue<int> q;

void bfs()
{
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int i = 1; i <= n; i++)
    {
      if (meet[node][i] && !visited[i])
      {
        visited[i] = true;
        know[i] = true;
        q.push(i);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  cin >> k;

  for (int i = 0; i < k; i++)
  {
    int num;
    cin >> num;
    know[num] = true;
    q.push(num);
  }

  for (int i = 0; i < m; i++)
  {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++)
    {
      int people;
      cin >> people;
      party[i].push_back(people);
    }

    for (int j = 0; j < num; j++)
    {
      for (int k = 0; k < num; k++)
      {
        if (j != k)
          meet[party[i][j]][party[i][k]] = true;
      }
    }
  }

  bfs();

  int ans = m;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < party[i].size(); j++)
    {
      if (know[party[i][j]])
      {
        ans--;
        break;
      }
    }
  }

  cout << ans << '\n';
}