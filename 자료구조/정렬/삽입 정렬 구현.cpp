#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX];

int main() {
    int n, i, j;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(i=1; i<n; i++){
        int key = arr[i];
        j = i-1;
        while(j>=0&& arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;    
    }

    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
