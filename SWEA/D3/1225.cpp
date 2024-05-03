#include <iostream>
#include <queue>
using namespace std;

int arr[8];

int main()
{
  for (int k = 1; k <= 10; k++)
  {
    int t;
    int num;
    cin >> t;
    queue<int> q;
    for (int i = 0; i < 8; i++)
    {
      cin >> num;
      q.push(num);
    }

    int minus = 1;
    while (1)
    {
      num = q.front() - minus;
      q.pop();

      if (num <= 0)
        break;

      q.push(num);
      minus++;

      if (minus > 5)
        minus = 1;
    }

    q.push(0);

    cout << "#" << k << " ";
    for (int i = 0; i < 8; i++)
    {
      cout << q.front() << " ";
      q.pop();
    }
    cout << '\n';
  }
}