#include <iostream>
#include <stack>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<char> st;
  string answer = "";
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '*' || str[i] == '/')
    {
      while (!st.empty())
      {
        if (st.top() == '*' || st.top() == '/')
        {
          answer += st.top();
          st.pop();
        }
        else
        {
          break;
        }
      }
      st.push(str[i]);
    }

    else if (str[i] == '+' || str[i] == '-')
    {
      while (!st.empty())
      {
        if (st.top() == '(')
        {
          break;
        }
        else
        {
          answer += st.top();
          st.pop();
        }
      }
      st.push(str[i]);
    }

    else if (str[i] == '(')
    {
      st.push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (!st.empty())
      {
        if (st.top() == '(')
        {
          st.pop();
          break;
        }
        else
        {
          answer += st.top();
          st.pop();
        }
      }
    }
    else
    {
      answer += str[i];
    }
  }

  while (!st.empty())
  {
    answer += st.top();
    st.pop();
  }

  cout << answer << '\n';
}
