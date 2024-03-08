#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> num;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num.push_back(a);
    }
    
    sort(num.begin(), num.end());

    int answer = num[n-1] - num[0];
    int start = 0;
    int end = 0;

    while(start<n&&end<n){
        int dif = num[end] - num[start];
        if(dif<m)
            end++;
        else {
            answer = min(answer, dif);
            start++;
        }
    }

    cout<<answer<<'\n';
}

