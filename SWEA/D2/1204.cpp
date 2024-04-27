#include <iostream>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    int num;
    cin >> num;
    map<int, int> student;
    for (int i = 0; i < 1000; i++)
    {
      int a;
      cin >> a;
      student[a]++;
    }

    int idx = 0;
    int number = 0;

    for (auto n : student)
    {
      if (number <= n.second)
      {
        idx = n.first;
        number = n.second;
      }
    }
    cout << "#" << i << " " << idx << '\n';
  }
}