#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
int n;
int arr[MAX];

void quick_sort(int low, int high) {
    if(low>=high){
        return;
    }

    int pivot = arr[high];
    int i= low;
    int j = high -1;
    int temp=0;

    while(i<=j){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<=j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quick_sort(low, i-1);
    quick_sort(i+1, high);
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quick_sort(0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
