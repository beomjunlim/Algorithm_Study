# 문제
https://inha.codetree.ai/missions/6/problems/implement-bubble-sort/explanation
# 풀이
가장 큰 값을 하나씩 비교하며 가장 마지막 위치로 하나씩 정렬한다.
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

# 문제
https://inha.codetree.ai/missions/6/problems/implement-selection-sort/submissions
# 풀이
가장 작은 부분을 하나씩 비교하며 작은 곳 부터 하나씩 정렬한다.
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
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/6/problems/implement-insertion-sort/submissions
# 풀이
앞의 배열은 모두 정렬되어있다고 하고, 현재 비교하는 배열을 key로 두어 key보다 작은 인덱스를 찾고, 그 앞에 삽입한다.
# 코드
```
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
```

# 문제
https://inha.codetree.ai/missions/6/problems/implement-radix-sort/submissions
# 풀이
기수 정렬은 가장 작은 자리수 부터 하나씩 정렬한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000
#define MAX_K 6
#define MAX_DIGIT 10

int n;
int arr[MAX_N];

void RadixSort() {
    int p = 1;
    for(int pos=0; pos<MAX_K; pos++){
        vector<int> arr_new[MAX_DIGIT];
        for(int i=0; i<n; i++){
            int digit = (arr[i]/p)%10;
            arr_new[digit].push_back(arr[i]);
        }

        int index=0;
        for(int i=0; i<MAX_DIGIT; i++){
            for(int j=0; j<(int)arr_new[i].size(); j++){
                arr[index++] = arr_new[i][j];
            }
        }
        p*=10;
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    RadixSort();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
