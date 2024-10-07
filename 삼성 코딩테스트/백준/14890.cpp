#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, l;
int answer = 0;
int A[101][101];
int B[101][101];

void Check(int road[][101]) {
    for (int i = 0; i < n; i++) {
        bool slope[101] = { 0 };
        bool possible = true;
        for (int j = 0; j < n - 1; j++) {
            if (abs(road[i][j] - road[i][j + 1]) > 1) {
                possible = false;
                break;
            }

            if (road[i][j] == road[i][j + 1] + 1) {
                int hight = road[i][j + 1];
                for (int k = j + 1; k < j + 1 + l; k++) {
                    if (k >= n || road[i][k] != hight) {
                        possible = false;
                        break;
                    }
                }
                if (possible)
                    slope[j + l] = true;
                else
                    break;
            }

            if (road[i][j] == road[i][j + 1] - 1) {
                int hight = road[i][j];
                for (int k = j; k > j - l; k--) {
                    if (k < 0 || road[i][k] != hight||slope[k]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible)
            answer++;
    }
}

int main() {
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            B[j][i] = A[i][j];
        }
    }
    
    Check(A);
    Check(B);

    cout << answer;
    return 0;
}
