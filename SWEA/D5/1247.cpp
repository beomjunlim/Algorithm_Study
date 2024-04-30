#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define INF 987654321

int n;
int ans;
int company_x;
int company_y;
int house_x;
int house_y;
vector<pair<int, int>> customer;
vector<int> route;
bool visited[11];

int myCalculate()
{
  int sum = 0;
  int x = company_x;
  int y = company_y;
  int nx, ny;

  for (int i = 0; i < route.size(); i++)
  {
    nx = customer[route[i]].first;
    ny = customer[route[i]].second;
    sum += (abs(x - nx) + abs(y - ny));
    x = nx;
    y = ny;
  }

  sum += (abs(x - house_x) + abs(y - house_y));
  return sum;
}

void sequence(int cnt)
{
  if (cnt == n)
  {
    int sum = myCalculate();
    ans = min(ans, sum);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      route.push_back(i);
      visited[i] = true;
      sequence(cnt + 1);
      route.pop_back();
      visited[i] = false;
    }
  }
}

int main()
{
  int t;
  cin >> t;

  for (int k = 1; k <= t; k++)
  {
    ans = INF;
    customer.clear();
    route.clear();
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      visited[i] = false;
    }

    for (int i = 0; i < n + 2; i++)
    {
      int a, b;
      cin >> a >> b;
      if (i == 0)
      {
        company_x = a;
        company_y = b;
      }
      else if (i == 1)
      {
        house_x = a;
        house_y = b;
      }
      else
      {
        customer.push_back(make_pair(a, b));
      }
    }

    sequence(0);
    cout << "#" << k << " " << ans << '\n';
  }
}