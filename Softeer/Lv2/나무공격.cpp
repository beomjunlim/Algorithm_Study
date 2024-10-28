#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
int arr[101][101];

int main(int argc, char** argv)
{
    cin >> n >> m;

    map<int, int> MAP;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            MAP[i] += num;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a - 1; j < b; j++)
        {
            if (MAP[j] > 0)
            {
                MAP[j]--;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += MAP[i];
    }

    cout << ans;
   return 0;
}
