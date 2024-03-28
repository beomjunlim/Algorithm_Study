#include <iostream>
#include <vector>
using namespace std;

int ans = 12;

int compareMbti(string a, string b)
{
  int cnt = 0;
  for (int i = 0; i < 4; i++)
  {
    if (a[i] != b[i])
      cnt++;
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, n;
  cin >> t;

  while (t > 0)
  {
    int one = 0;
    int two = 0;
    int thr = 0;
    cin >> n;
    vector<string> mbti(n);
    ans = 12;
    for (int i = 0; i < n; i++)
    {
      cin >> mbti[i];
    }

    if (n > 32)
    {
      cout << 0 << '\n';
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = i + 1; j < n; j++)
        {
          for (int k = j + 1; k < n; k++)
          {
            one = compareMbti(mbti[i], mbti[j]);
            two = compareMbti(mbti[i], mbti[k]);
            thr = compareMbti(mbti[j], mbti[k]);
            ans = min(ans, one + two + thr);
          }
        }
      }
      cout << ans << '\n';
    }
    t--;
  }
}