#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

#define MAX 500000
char arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int blue = 1;
    int red = 1;
    if(arr[0]=='B')
        blue += 1;
    else
        red += 1;

    for(int i=1; i<n; i++){
        if(arr[i]=='B'&&arr[i-1]!='B'){
            blue += 1;
        }
        if(arr[i]=='R'&&arr[i-1]!='R')
            red += 1;
    }

    cout<<min(blue,red);
}
