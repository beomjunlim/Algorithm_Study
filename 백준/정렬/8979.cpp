#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Country
{
    int num, g, s, b;
};

int n, k;
vector<Country> country;

bool cmp(Country a, Country b)
{
    if (a.g != b.g)
        return a.g > b.g;
    if (a.s != b.s)
        return a.s > b.s;
    return a.b > b.b;
}

int main(int argc, char **argv)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        country.push_back({A, B, C, D});
    }

    sort(country.begin(), country.end(), cmp);

    int ans = 0;
    int count = 0;
    int cntN = country[0].num;
    int cntG = country[0].g;
    int cntS = country[0].s;
    int cntB = country[0].b;

    if (cntN != k)
    {
        int same = 1;
        for (int i = 1; i < n; i++)
        {
            int curN = country[i].num;
            int curG = country[i].g;
            int curS = country[i].s;
            int curB = country[i].b;

            if (cntG == curG && cntS == curS && cntB == curB)
                same++;
            else
            {
                count += same;
                same = 1;
            }

            if (curN == k)
            {
                ans = count;
                break;
            }
            cntG = curG;
            cntS = curS;
            cntB = curB;
        }
    }

    cout << ans + 1 << '\n';
    return 0;
}
