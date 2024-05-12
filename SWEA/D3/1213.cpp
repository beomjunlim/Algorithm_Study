#include <iostream>
using namespace std;

int main()
{

  for (int k = 1; k <= 10; k++)
  {
    int t;
    int cnt = 0;
    cin >> t;

    string ans, str;
    cin >> ans;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
      if (ans == str.substr(i, ans.length()))
      {
        cnt++;
        i += ans.length();
      }
    }
    cout << "#" << t << " " << cnt << '\n';
  }
}