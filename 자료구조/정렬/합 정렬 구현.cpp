#include <iostream>
using namespace std;

#define MAX 100000

int n;
int arr[MAX];
int sorted_arr[MAX];

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid&&j<=high){
        if(arr[i]<arr[j]){
            sorted_arr[k] = arr[i];
            k++;
            i++;
        } else {
            sorted_arr[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
        sorted_arr[k] = arr[i];
        k++;
        i++;
    }

    while(j<=high){
        sorted_arr[k] = arr[j];
        k++;
        j++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = sorted_arr[i];
    }
}

void merge_sort(int arr[], int low, int high) {
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr,low, mid);
        merge_sort(arr,mid+1, high);
        merge(arr, low, mid, high);
    }
}


int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
