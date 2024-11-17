#include<iostream>
#include<cstring>

using namespace std;

int A[10];
int B[10];
int win = 0;
int lose = 0;
bool selected[10];

void backtracking(int cnt, int aScore, int bScore) {
    if (cnt == 9) {
        if (aScore > bScore) win++;
        else if (aScore < bScore) lose++;
        return;
    }
    
    for (int i = 0; i < 9; i++) {
        if (!selected[i]) {
            selected[i] = true;
            int score = A[cnt] + B[i];
            if (A[cnt] > B[i])
                backtracking(cnt + 1, aScore + score, bScore);
            else
                backtracking(cnt + 1, aScore, bScore + score);
            selected[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        bool visited[19] = {0};

        for (int i = 0; i < 9; i++) {
            cin >> A[i];
            visited[A[i]] = true;
        }

        int cnt = 0;
        for (int i = 1; i <= 18; i++) {
            if (!visited[i]) {
                B[cnt] = i;
                cnt++;
            }
        }

        memset(selected, false, sizeof(selected));
        win = 0;
        lose = 0;
        backtracking(0, 0, 0);
        cout << "#" << test_case << " " << win << " " << lose << '\n';
    }

    return 0;
}
