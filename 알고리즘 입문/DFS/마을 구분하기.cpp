#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 26

int n;
int cnt;
int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool InRange(int i, int j){
    return 0<=i&&i<n&&0<=j&&j<n;
}

void DFS(int i, int j){
    for(int k=0; k<n; k++){
        int ni= i + dx[k];
        int nj= j + dy[k];
        if(!visited[ni][nj]&&InRange(ni,nj)&&arr[ni][nj]==1){
            visited[ni][nj]=true;
            cnt+=1;
            DFS(ni,nj);
        }
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&arr[i][j]==1){
                visited[i][j]=true;
                cnt=1;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}
