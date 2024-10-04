#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,k;
int arr[10001][10001];
int dist[10001];

int main() {
	cin>>n>>m>>k;
	
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		arr[a][b] = 1;
	}

	for(int i=1; i<=n; i++){
		dist[i] = INT_MAX;
	}
	
	dist[k] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(0,k));
	
	while(!q.empty()){
		int cnt = q.front().first;
		int node = q.front().second;
		q.pop();
		
		if(dist[node]<cnt)
			continue;
		
		for(int i=1; i<=n; i++){
			if(arr[node][i]&&dist[i]>cnt+1){
				dist[i] = cnt + 1;
				q.push(make_pair(cnt+1, i));
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		if(i!=k&&dist[i]!=INT_MAX){
			dist[i] += abs(k-i);
		}
	}
	
	int answer = -1;
	int num = 0;
	for(int i=1; i<=n; i++){
		if(i!=k&&dist[i]!=INT_MAX&&num<=dist[i]){
			num = dist[i];
			answer = i;
		}
	}
	
	cout<<answer;
	return 0;
}
