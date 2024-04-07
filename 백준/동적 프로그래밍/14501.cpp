#include <iostream>
#include <algorithm>
using namespace std;

int day[16];
int pay[16];
int ans[16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> day[i] >> pay[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i + day[i] <= n)
        {
            ans[i] = max(ans[i + 1], ans[i + day[i]] + pay[i]);
        }
        else
        {
            ans[i] = ans[i + 1];
        }
        answer = max(answer, ans[i]);
    }

    cout << answer;
}