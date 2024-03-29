#include <iostream>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, string> memo;
  string site, pwd;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> site >> pwd;
    memo[site] = pwd;
  }

  for (int i = 0; i < m; i++)
  {
    cin >> site;
    cout << memo[site] << '\n';
  }
}