#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int arr[1001];
int temp[1001];
int s[100001];
int e[100001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		temp[i] = arr[i];
	}
	
	for(int i=1; i<=m; i++){
		cin>>s[i]>>e[i];		
	}
	
	set<int> rain;
	for(int i=1; i<=m; i++){
		for(int j=s[i]; j<=e[i]; j++){
			rain.insert(j);
			temp[j]--;
		}
		
		if(i%3==0){
			for(auto it : rain){
				temp[it]++;
			}
			rain = set<int> ();
		}
	}
	
	for(int i=1; i<=n; i++){
		arr[i] += abs(arr[i]-temp[i]);
	}
	
	for(int i=1; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
