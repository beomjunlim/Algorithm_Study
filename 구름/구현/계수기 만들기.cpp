#include <iostream>
using namespace std;

int maxNum[9];
int arr[9];

int main() {
	int n,k;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>maxNum[i];
	}
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	cin>>k;
	
	for(int i=k; i>0; i--){
		arr[n]++;
		if(arr[n]>maxNum[n]){
			arr[n] = 0;
			for(int i=n-1; i>0; i--){
				arr[i]++;
				if(arr[i]<=maxNum[i])
					break;
				else{
					arr[i] = 0;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		cout<<arr[i];
	}
	return 0;
}
