#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 11
int n;
int arr[MAX][MAX];
bool visited[MAX];
vector<int> v;
int max_num=0;

void Check(int num){
    if(num==n){
        int sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i][v[i]];
        }
        max_num = max(max_num, sum);
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            
            Check(num+1);

            visited[i]=false;
            v.pop_back();
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

    Check(0);
    cout<<max_num<<'\n';
    return 0;
}
