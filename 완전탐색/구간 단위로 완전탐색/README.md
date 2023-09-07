# 문제
https://inha.codetree.ai/missions/5/problems/max-sum-of-subarray/submissions
# 풀이
구간의 범위를 잘 생각해서 풀어야 한다.
# 코드
``` 
#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];

int main() {
    int n,k;
    int max_num=0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<=n-k; i++){
        int num=0;
        for(int j=i; j<i+k; j++){
            num+=arr[j];
        }
        if(max_num<num)
            max_num = num;
    }
    cout<<max_num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/G-or-H-3/submissions
# 풀이
모든 경우의 수를 계산한다. 구간을 선택할 때 차를 생각한다.
# 코드
```
#include <iostream>
#include <climits>
using namespace std;

#define MAX 10001
int arr[MAX];

int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        char s;
        int a;
        cin>>a>>s;

        if(s=='G')
            arr[a]=1;
        if(s=='H')
            arr[a]=2;
    }

    int max_sum=0;
    for(int i=1; i<=MAX-k+1; i++){
        int sum=0;
        for(int j=i; j<=i+k; j++){
            sum+=arr[j];
        }
        if(max_sum<sum)
            max_sum=sum;
    }
    cout<<max_sum;


    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/elemental-mean-value-for-a-particular-interval/submissions
# 풀이
평균을 구할 때 타입을 변환시키는게 중요하다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 101
int arr[MAX];

int main() {
    int n,i,j,k;
    int res=0;
    bool sw;
    
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+=arr[k];
            }

            double avg = (double)sum/(j-i+1);
            bool sw=false;
            for(int k=i; k<=j; k++){
                if(arr[k]==avg)
                    sw = true;
            }
            if(sw)
                res+=1;
        }
    }
    
    cout<<res<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/5/problems/beautiful-sequence-2/submissions
# 풀이
구간을 정해두고 비교하기 위해 새로운 m 크기 배열에 담아 정렬을 한 다음 m 배열과 똑같은지 확인한다.
# 코드
```
#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 100
int arr_n[MAX];
int arr_m[MAX];
int tmp[MAX];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr_n[i];
    }

    for(int i=0; i<m; i++){
        cin>>arr_m[i];
    }
    sort(arr_m,arr_m+m);

    int cnt=0;

    for(int i=0; i<=n-m; i++){
        for(int j=0; j<m; j++){
            tmp[j]=arr_n[i+j];
        }
        sort(tmp,tmp+m);

        bool sw = true;

        for(int j=0; j<m; j++){
            if(tmp[j]!=arr_m[j]){
                sw = false;
                break;
            }
        }
        if(sw)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
```

# 문제

# 풀이

# 코드
```

```
