#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int weight[MAX + 1];
int value[MAX + 1];
int dp[MAX + 1][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (weight[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}
