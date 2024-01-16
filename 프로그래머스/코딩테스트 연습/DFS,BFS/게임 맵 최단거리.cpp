// https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp
#include<vector>
#include<queue>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


bool InRange(int x, int y, int n, int m){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = true;
    arr[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny,n,m)&&maps[nx][ny]==1&&!visited[nx][ny]){
                q.push(make_pair(nx,ny));
                arr[nx][ny] = arr[x][y] + 1;
                visited[nx][ny] = true;
            }
        }
    }
    
}

int solution(vector<vector<int> > maps)
{
    bfs(maps);
    int answer = 0;
    if(!visited[maps.size()-1][maps[0].size()-1])
        answer = -1;
    else
        answer = arr[maps.size()-1][maps[0].size()-1];
    
    return answer;
}
