#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int start, dest;
vector<int> node1[100001];
vector<int> node2[100001];
bool visitedS1[100001];
bool visitedS2[100001];
bool visitedE1[100001];
bool visitedE2[100001];

void dfsS1(int a)
{
    if (visitedS1[a])
        return;
    visitedS1[a] = true;

    for (int i = 0; i < node1[a].size(); i++)
    {
        dfsS1(node1[a][i]);
    }
}

void dfsE1(int a)
{
    if (visitedE1[a])
        return;
    visitedE1[a] = true;

    for (int i = 0; i < node1[a].size(); i++)
    {
        dfsE1(node1[a][i]);
    }
}

void dfsS2(int a)
{
    if (visitedS2[a])
        return;
    visitedS2[a] = true;

    for (int i = 0; i < node2[a].size(); i++)
    {
        dfsS2(node2[a][i]);
    }
}

void dfsE2(int a)
{
    if (visitedE2[a])
        return;
    visitedE2[a] = true;

    for (int i = 0; i < node2[a].size(); i++)
    {
        dfsE2(node2[a][i]);
    }
}

int main(int argc, char **argv)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        node1[a].push_back(b);
        node2[b].push_back(a);
    }

    cin >> start >> dest;

    visitedS1[dest] = true;
    visitedE1[start] = true;
    dfsS1(start);
    dfsE1(dest);
    dfsS2(start);
    dfsE2(dest);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visitedS1[i] && visitedS2[i] && visitedE1[i] && visitedE2[i])
            ans++;
    }
    cout << ans - 2;
    return 0;
}
