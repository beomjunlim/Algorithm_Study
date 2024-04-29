#include <iostream>
#include <vector>
using namespace std;

int n;
int score[101];
bool visited[10001];

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    int sum = 0;
    int ans = 0;
    cin >> n;

    for (int i = 0; i < 10001; i++)
    {
      visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
      cin >> score[i];
      sum += score[i];
    }

    visited[0] = true;

    for (int i = 0; i < n; i++)
    {
      vector<int> v;
      for (int j = 0; j <= sum; j++)
      {
        if (visited[j])
        {
          v.push_back(j + score[i]);
        }
      }

      for (int i = 0; i < v.size(); i++)
      {
        visited[v[i]] = true;
      }
    }

    for (int i = 0; i <= sum; i++)
    {
      if (visited[i])
      {
        ans++;
      }
    }

    cout << "#" << k << " " << ans << '\n';
  }
}