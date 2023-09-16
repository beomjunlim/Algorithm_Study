# 문제
https://inha.codetree.ai/missions/2/problems/conveyor-belt/submissions
# 풀이
배열의 가장 마지막 부분을 temp 변수를 이용해서 저장하고 나머지 배열의 원소를 한칸씩 뒤로 옮기고 마지막에 배열의 첫번째에 temp 값을 넣어주며 배열을 업데이틀한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 200
int arr[MAX];

int main() {
    int n,t;
    cin>>n>>t;
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }

    while(t!=0){
        int temp=arr[2*n-1];
        for(int i=2*n-2; i>=0; i--){
            arr[i+1]=arr[i];
        }
        arr[0]=temp;
        t--;
    }
    for(int i=0; i<2*n; i++){
        if(i==n)
            cout<<'\n';
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
