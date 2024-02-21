#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[3] = {1,2,3};
    do{
        for(int i=0; i<3; i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    } while(next_permutation(arr, arr+3));
}
