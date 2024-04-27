#include <iostream>
#include <algorithm>
using namespace std;

string num;
int change;
int answer = 0;

void dfs(int idx, int cnt)
{
  if (cnt == change)
  {
    answer = max(answer, stoi(num));
    return;
  }

  for (int i = idx; i < num.length() - 1; i++)
  {
    for (int j = i + 1; j < num.length(); j++)
    {
      if (num[i] <= num[j])
      {
        swap(num[i], num[j]);
        dfs(i, cnt + 1);
        swap(num[i], num[j]);
      }

      if (i == num.length() - 2 && j == num.length() - 1)
      {
        swap(num[i], num[j]);
        dfs(i, cnt + 1);
        swap(num[i], num[j]);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int c;
  cin >> c;

  for (int i = 1; i <= c; i++)
  {
    cin >> num >> change;
    answer = 0;
    dfs(0, 0);
    cout << "#" << i << " " << answer << '\n';
  }
}