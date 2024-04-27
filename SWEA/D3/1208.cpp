#include <iostream>
#include <queue>
using namespace std;

int arr[100];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int t = 1; t <= 10; t++)
  {
    priority_queue<int> pq_front;
    priority_queue<int> pq_back;
    int dump;
    cin >> dump;
    for (int i = 0; i < 100; i++)
    {
      cin >> arr[i];
      pq_front.push(arr[i]);
      pq_back.push(-arr[i]);
    }

    for (int i = 0; i < dump; i++)
    {
      int max_num = pq_front.top();
      pq_front.pop();
      int min_num = pq_back.top();
      pq_back.pop();
      pq_front.push(max_num - 1);
      pq_back.push(min_num - 1);
    }

    int max_num = pq_front.top();
    int min_num = -pq_back.top();
    int ans = max_num - min_num;
    cout << "#" << t << " " << ans << '\n';
  }
}