#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define MAX 21
int n;
int arr[MAX];
bool visited[MAX*100000 + 1];

void cnt(int index, int sum){
    if(index>n) return;
    visited[sum] = true;
    cnt(index + 1, sum + arr[index]);
    cnt(index + 1, sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int num = 1;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cnt(0,0);

    while(visited[num]) num++;
    cout<<num<<'\n';
}


