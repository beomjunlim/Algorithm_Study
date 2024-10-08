#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int N, K;
vector<pair<int, int >> house;
int dist[51][51];
int ans[3];
int answer = INT_MAX;

void backtracking(int idx, int num) {
    if (idx == K) {
        int cnt[51];

        for (int i = 0; i < N; i++)
            cnt[i] = INT_MAX;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < idx; j++) {
                cnt[i] = min(dist[ans[j]][i], cnt[i]);
            }
        }

        int num = 0;

        for (int i = 0; i < N; i++)
            num = max(num, cnt[i]);

        answer = min(answer, num);
        return;
    }

    for (int i = num; i < N; i++) {
        ans[idx] = i;
        backtracking(idx + 1, i+1);
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        house.push_back({ a,b });
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = abs(house[i].first - house[j].first) + abs(house[i].second - house[j].second);
        }
    }

    backtracking(0, 0);

    cout << answer;
    return 0;
}
