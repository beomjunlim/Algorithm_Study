#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

#define MAX 11

int n;
int arr[MAX][MAX];
bool visited[MAX];
vector<int> v;
int max_num = 0;

int Min_num(){
    int num = INT_MAX;
    for(int i=0; i<n; i++){
        if(num>v[i]){
            num = v[i];
        }
    }
    return num;
}

void Chechk(int num){
    if(num==n){
        max_num = max(max_num, Min_num());
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(arr[num][i]);
            Chechk(num+1);
            visited[i] = false;
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
    Chechk(0);
    cout<<max_num;
    return 0;
}
