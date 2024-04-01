#include <iostream>
#include <deque>
using namespace std;

int arr[100001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string fun;
  int t, n;
  string num;
  cin >> t;

  while (t > 0)
  {
    bool dir = true;
    bool sw = true;
    deque<int> dq;
    cin >> fun;
    cin >> n;
    cin >> num;

    int num_idx = 0;
    int arr_idx = -1;
    string arr_num = "";
    while (num[num_idx] != ']')
    {
      if (num[num_idx] == '[')
        num_idx++;
      else if (num[num_idx] == ',')
      {
        arr_idx++;
        arr[arr_idx] = stoi(arr_num);
        num_idx++;
        arr_num = "";
      }
      else
      {
        arr_num += num[num_idx];
        num_idx++;
      }
    }

    if (arr_num != "")
    {
      arr_idx++;
      arr[arr_idx] = stoi(arr_num);
    }

    for (int i = 0; i <= arr_idx; i++)
    {
      dq.push_back(arr[i]);
    }

    for (int i = 0; i < fun.length(); i++)
    {
      if (fun[i] == 'R')
      {
        dir = !dir;
      }
      else
      {
        if (dq.empty())
        {
          sw = false;
          break;
        }
        else
        {
          if (dir)
          {
            dq.pop_front();
          }
          else
          {
            dq.pop_back();
          }
        }
      }
    }
    if (sw)
    {
      cout << "[";
      if (dir)
      {
        for (int i = 0; i < dq.size(); i++)
        {
          cout << dq[i];
          if (i != dq.size() - 1)
            cout << ",";
        }
      }
      else
      {
        for (int i = dq.size() - 1; i >= 0; i--)
        {
          cout << dq[i];
          if (i != 0)
            cout << ",";
        }
      }

      cout << "]" << '\n';
    }
    else
    {
      cout << "error" << '\n';
    }

    t--;
  }
}