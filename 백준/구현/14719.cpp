#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w;
    cin>>h>>w;

    int sum = 0;

    vector<int> v(w);
    
    for(int i=0; i<w; i++){
        cin>>v[i];
    }

    for(int i=1; i<w-1; i++){
        int left = 0;
        int right = 0;
        for(int j=0; j<i; j++){
            if(v[j]>v[i]){
                left = max(left, v[j]);
            }
        }
        for(int j=i+1; j<w; j++){
            if(v[j]>v[i]){
                right = max(right, v[j]);
            }
        }
        sum += max(0,min(left, right) - v[i]);
    }
    cout<<sum<<'\n';
}
