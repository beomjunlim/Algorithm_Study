#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<char> st;
  vector<char> answer;
  string s;
  getline(cin, s);

  int idx = 0;
  while (idx < s.length())
  {
    if (s[idx] == '<')
    {
      if (!st.empty())
      {
        while (!st.empty())
        {
          answer.push_back(st.top());
          st.pop();
        }
      }
      while (s[idx] != '>')
      {
        answer.push_back(s[idx]);
        idx++;
      }
      answer.push_back(s[idx]);
    }
    else if (s[idx] != ' ')
    {
      st.push(s[idx]);
    }
    else if (s[idx] == ' ')
    {
      while (!st.empty())
      {
        answer.push_back(st.top());
        st.pop();
      }
      answer.push_back(s[idx]);
    }
    idx++;
  }

  while (!st.empty())
  {
    answer.push_back(st.top());
    st.pop();
  }

  for (int i = 0; i < answer.size(); i++)
  {
    cout << answer[i];
  }
}