# 문제
https://inha.codetree.ai/missions/6/problems/implement-bubble-sort/explanation
# 풀이
거품 정렬의 코드를 작성한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101

int arr[MAX];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
