#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(int argc, char **argv)
{
    int w, n;
    cin >> w >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), cmp);

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int weight = v[i].first;
        int value = v[i].second;

        if(sum + weight<=w){
            ans += value*weight;
            sum += weight;
        }
        else{
            ans += value*(w-sum);
            break;
        }
    }

    cout << ans;

    return 0;
}
