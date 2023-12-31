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
https://inha.codetree.ai/missions/2/problems/tromino/explanation
# 풀이
가능한 케이스 두개를 나눠서 함수를 만들어서 경우를 계산하였다.
# 코드
```
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200
int arr[MAX][MAX];
int n,m;

bool InRange(int i, int j){
    return 0<=i&&i<n&&0<=j&&j<m;
}

int CheckCase1(int i, int j){
    int num=0;
    if(InRange(i+1,j)&&InRange(i,j+1)){
        int min_num=min(arr[i][j], min(arr[i+1][j], min(arr[i][j+1], arr[i+1][j+1])));
        num=(arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1]-min_num);
    }
    return num;
}

int CheckCase2(int i, int j){
    int num1=0;
    int num2=0;
    if(InRange(i+2,j)){
        num1=(arr[i][j]+arr[i+1][j]+arr[i+2][j]);
    }
    if(InRange(i,j+2)){
        num2=(arr[i][j]+arr[i][j+1]+arr[i][j+2]);
    }
    return  max(num1,num2);
}

int main() {

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int case1=0;
    int case2=0;
    int max_num=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            case1=CheckCase1(i,j);
            case2=CheckCase2(i,j);
            int max_case=max(case1, case2);
            if(max_num<max_case)
                max_num = max_case;
        }
    }
    cout<<max_num;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/gold-mining/submissions
# 풀이
k의 범위가 어떻게 되는지를 잘 생각하고, 함수를 작성해야 한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 20
int arr[MAX][MAX];
int n,m;

int GetArea(int k){
    return k*k+(k+1)*(k+1);
}

int GetGold(int i, int j, int k){
    int gold=0;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            if(abs(i-a)+abs(j-b)<=k)
                gold+=arr[a][b];
        }
    }
    return gold;
}

int main() {
    int max_gold=0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<=2*(n-1); k++){
                int gold= GetGold(i,j,k);
                if(gold*m>=GetArea(k))
                    max_gold = max(max_gold, gold);
            }
        }
    }
    cout<<max_gold;

    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/slanted-rectangle/submissions
# 풀이
대각선으로 움직이는 횟수를 정해두고 함수로 들어가서 합을 반환하며 비교한다.
# 코드
```
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 21
int arr[MAX][MAX];
int n;
int dx[]={1,-1,-1,1},dy[]={-1,-1,1,1};

bool InRange(int i, int j){
    return 1<=i&&i<=n&&1<=j&&j<=n;
}

int GetScore(int y,int x, int k, int l){
    int move_num[]={k,l,k,l};
    int sum=0;
    for(int d=0; d<4; d++){
        for(int q=0; q<move_num[d]; q++){
            x+=dx[d];
            y+=dy[d];
            if(!InRange(x,y))
                return 0;
            sum+=arr[y][x];
        }
    }
    return sum;
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<n; k++){
                for(int l=1; l<n; l++)
                    ans = max(ans, GetScore(i,j,k,l));
            }
        }
    }
    cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/non-overlapping-two-rectangles/submissions
# 풀이
먼저 첫번째 사각형을 완성시키고 두번째 사각형을 만들어서 둘이 겹치는지 확인 후 겹치지않는다면 넓이를 계산하여 최대값을 찾는 형식으로 풀었다.  
겹치는지 확인하는 함수는 이 칸을 방문한 적이 있는지 확인하며 겹치는지 여부를 확인했다.
# 코드
```
#include <iostream>
#include <climits>
using namespace std;

#define MAX 5

int arr[MAX][MAX];
bool visited[MAX][MAX];
int n,m;

int checkSum(int x1, int x2, int y1, int y2){
    int sum=0;
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

void intializeVisited() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=false;
        }
    }
}

bool checkArea(int x1, int x2, int y1, int y2, int z1, int z2, int k1, int k2) {
    intializeVisited();
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            visited[i][j]=true;
        }
    }

    for(int i=k1; i<=k2; i++){
        for(int j=z1; j<=z2; j++){
            if(visited[i][j])
                return false;
        }
    }
    return true;
}

int MaxArea(int x1, int x2, int y1, int y2){
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=i; k<n; k++){
                for(int l=j; l<m; l++){
                    if(checkArea(x1,x2,y1,y2,j,l,i,k)){
                        sum=checkSum(x1,x2,y1,y2)+checkSum(j,l,i,k);
                        if(max_sum<sum)
                            max_sum=sum;
                    }
                }
            }
        }
    }
    return max_sum;
}



int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=i; k<n; k++){
                for(int l=j; l<m; l++){
                    sum=MaxArea(j,l,i,k);
                    if(max_sum<sum)
                        max_sum=sum;
                }
            }
        }
    }
    cout<<max_sum;
    return 0;
}
```

# 문제

# 풀이

# 코드
```

```
