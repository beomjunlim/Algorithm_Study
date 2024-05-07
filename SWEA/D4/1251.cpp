#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long ans;
int n;
int parent[1000];
vector<pair<long long, pair<int, int>>> dis;

bool cmp(pair<long long, pair<int, int>> a, pair<long long, pair<int, int>> b)
{
  return a.first < b.first;
}

// 부모 노드 가져오는 함수
int getParent(int node)
{
  if (parent[node] == node)
    return node;
  else
    return getParent(parent[node]);
}

// 부모 노드 통합시키는 함수
void unionParent(int nodeA, int nodeB)
{
  nodeA = getParent(nodeA);
  nodeB = getParent(nodeB);
  if (nodeA < nodeB)
    parent[nodeB] = nodeA;
  else
    parent[nodeA] = nodeB;
}

bool isCycle(int nodeA, int nodeB)
{
  nodeA = getParent(nodeA);
  nodeB = getParent(nodeB);
  if (nodeA == nodeB)
    return true;
  else
    return false;
}

int main()
{
  int k;
  cin >> k;

  for (int t = 1; t <= k; t++)
  {
    dis.clear();
    ans = 0;
    cin >> n;

    pair<int, int> arr[n];

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      arr[i].first = x;
    }

    for (int i = 0; i < n; i++)
    {
      int y;
      cin >> y;
      arr[i].second = y;
    }

    double E;
    cin >> E;

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        long long sum = 0;
        sum += pow(arr[i].first - arr[j].first, 2);
        sum += pow(arr[i].second - arr[j].second, 2);
        dis.push_back(make_pair(sum, make_pair(i, j)));
      }
    }

    sort(dis.begin(), dis.end(), cmp);

    for (int i = 0; i < dis.size(); i++)
    {
      if (isCycle(dis[i].second.first, dis[i].second.second) == false)
      {
        ans += dis[i].first;
        unionParent(dis[i].second.first, dis[i].second.second);
      }
    }

    cout << fixed;
    cout.precision(0);

    cout << "#" << t << " " << (double)(ans * E) << '\n';
  }
}
