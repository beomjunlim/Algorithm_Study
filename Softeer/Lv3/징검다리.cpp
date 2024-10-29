#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[3001];
int arr[3001];

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int num = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] > num)
            {
                num = dp[j];
            }
        }
        dp[i] = num + 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
