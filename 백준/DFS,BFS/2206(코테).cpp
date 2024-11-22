#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct BFS
{
    int x, y, cnt, broke;
};

int n, m;
char arr[1001][1001];
bool visited[1001][1001][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = -1;
    queue<BFS> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int broke = q.front().broke;
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            ans = cnt;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny))
            {
                if (arr[nx][ny] == '1' && broke == 0 && !visited[nx][ny][1])
                {
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, cnt + 1, 1});
                }

                if (arr[nx][ny] == '0' && !visited[nx][ny][broke])
                {
                    visited[nx][ny][broke] = true;
                    q.push({nx, ny, cnt + 1, broke});
                }
            }
        }
    }

    cout << ans;
    return 0;
}
