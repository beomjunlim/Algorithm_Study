# 문제
https://inha.codetree.ai/missions/2/problems/best-place-of-33/submissions
# 풀이
격자 크기를 기준으로 시작점부터 for문을 이용해서 합을 구한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 21

int arr[MAX][MAX];

int CheckCoin(int i, int j){
    int sum=0;
    for(int a=i; a<i+3; a++){
        for(int b=j; b<j+3; b++){
            sum+=arr[a][b];
        }
    }
    return sum;
}

int main() {
    int n;
    int max_num=0;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=(n-2); i++){
        for(int j=1; j<=(n-2); j++){
            int num=0;
            num=CheckCoin(i,j);
            if(max_num<num)
                max_num=num;
        }
    }
    cout<<max_num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/number-of-happy-sequence/submissions
# 풀이
행과 열을 따로 생각해서 함수를 만들어서 경우를 생각한다.
# 코드
```
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
int arr[MAX][MAX];
int n,m;

bool checkRow(int i){
    int start=arr[i][0];
    int num=1;
    int max_num=1;
    for(int j=1; j<n; j++){
        if(arr[i][j]==start)
            num+=1;
        else
            num=1;

        max_num=max(num, max_num);
        start=arr[i][j];
    }
    if(max_num>=m)
        return true;
    else
        return false;
}

bool checkCol(int i){
    int start=arr[0][i];
    int num=1;
    int max_num=1;
    for(int j=1; j<n; j++){
        if(arr[j][i]==start)
            num+=1;
        else
            num=1;

        max_num=max(num, max_num);
        start=arr[j][i];
    }
    if(max_num>=m)
        return true;
    else
        return false;
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        if(checkRow(i))
            sum+=1;
        if(checkCol(i))
            sum+=1;
    }
    cout<<sum<<'\n';
    return 0;
}
```

# 문제

# 풀이

# 코드
```

```
