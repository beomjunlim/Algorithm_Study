#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		int x,y,t;
		cin>>x>>y>>t;
		bool sw = false;
		int total = abs(x) + abs(y);
		
		if(total>t)
			sw = false;
		else{
			if((total-t)%2==0)
				sw = true;
			else
				sw = false;
		}
		
		if(sw)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}
