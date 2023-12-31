# 문제
https://inha.codetree.ai/missions/2/problems/n-permutations-of-k-with-repetition/introduction
# 풀이
길이를 종료조건으로 두고 for문을 이용해 순서대로 하나씩 넣어보며 출력한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> v;

void print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        print();
        return;
    }
    else{
        for(int i=1; i<=k; i++){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>k>>n;
    Check(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/beautiful-number/submissions
# 풀이
백트래킹을 이용해서 경우를 하나씩 살펴보면서 아름다운 수를 확인해본다.  
배열 안의 숫자를 비교해가면서 아름다운 수를 확인한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
vector<int> v;
int n;
int res=0;

bool BtfNum(){
    int cnt=0;
    int i=0;
    while(i!=n){
        int k=v[i];
        cnt=1;
        while(k!=cnt){
            i++;
            if(i==n||k!=v[i])
                return false;
            cnt++;
        }
        i++;
    }
    return true;
}

void Check(int num){
    if(num==n){
        if(BtfNum())
            res++;
        return;
    }
    else{
        for(int i=1; i<=4; i++){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>n;
    Check(0);
    cout<<res<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/select-segments-without-overlap/description
# 풀이
선분이 겹치는지 좌표를 계산해서 가능한 경우를 계산한다 계산하는 경우에 대해 다시 생각해 봐야겠다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

int n;
int ans=0;
vector<pair<int, int>>v;
vector<pair<int, int>>w;

bool Overlapped(pair<int, int>a, pair<int, int>b){
    int ax=a.first;
    int ay=a.second;
    int bx=b.first;
    int by=b.second;

    return (ay<bx||by<ax);
}

bool Possible(){
    for(int i=0; i<(int)w.size(); i++){
        for(int j=i+1; j<(int)w.size(); j++){
            if(!Overlapped(w[i], w[j]))
                return false;
        }
    }
    return true;
}

void Check(int num){
    if(num==n){
        if(Possible())
            ans = max(ans,(int)w.size());
        return;
    }
    w.push_back({v[num].first,v[num].second});
    Check(num+1);
    w.pop_back();
    Check(num+1);
}

int main() {

    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    Check(0);
    cout<<ans;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/n-permutations-of-k-with-repetition-under-constraint/submissions
# 풀이
연속으로 나오는 경우가 제한되어있으므로 이전 두번 어떤 숫자가 나왔는지 비교하기 위해 if문을 넣는다 하지만 index오류가 발생할 수 있으므로 먼저 indexrk 0보다 적어지는 경우를 제외한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void Print() {
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        Print();
        return;
    }

    for(int i=1; i<=k; i++){
        if(v.size()>=2&&i==v[num-1]&&i==v[num-2]){
            continue;
        } else{
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>k>>n;
    Check(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/yutnori-1d/submissions
# 풀이
말의 위치를 담는 배열을 따로 만들고, 말이 더 이상 움직일 수 없을 때 와 움직일 수 있을 때를 나눠준다.  
BackTracking 을 위치를 다시 되돌리며 사용한다.
# 코드
```
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 12
#define MAX_K 4

int n,m,k;
int max_num=0;
int sco[MAX_N];
int pie[MAX_K];

int print(){
    int sum=0;
    for(int i=0; i<k; i++){
        if(pie[i]>=m)
            sum+=1;
    }
    return sum;
}

void Check(int num){
    max_num = max(max_num, print());
    
    if(num==n){
        return;
    }

    for(int i=0; i<k; i++){
        if(pie[i]>=m)
            continue;
        pie[i]+=sco[num];
        Check(num+1);
        pie[i]-=sco[num];
    }
}

int main() {
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        cin>>sco[i];
    }
    for(int i=0; i<k; i++){
        pie[i]=1;
    }
    Check(0);
    cout<<max_num;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/max-movements-with-direction/submissions
# 풀이
현 위치의 숫자와 바라보는 방향을 저장하고 Check하기 위한 함수로 넣어준다. 그러고 격자내에 위치한 지 확인하며 이동하고 조건에 맞지않는다면 그 전 저장한 위치로 돌아간다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 4
int n;
int num;
int dir_num=0;
int cnt=0;
int max_num=0;
int arr[MAX][MAX];
int dir[MAX][MAX];
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={-1,-1,0,1,1,1,0,-1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void Check(int x, int y,int num, int dir_num){
    int nx=x+dx[dir_num];
    int ny=y+dy[dir_num];

    while(InRange(nx,ny)){
        if(num<arr[ny][nx]){
            cnt+=1;
            Check(nx,ny,arr[ny][nx],dir[ny][nx]-1);
            cnt-=1;
        }
        nx=nx+dx[dir_num];
        ny=ny+dy[dir_num];
    }
    max_num = max(max_num,cnt);
}


int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dir[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    dir_num=dir[r-1][c-1];
    num=arr[r-1][c-1];
    Check(c-1,r-1,num,dir_num-1);
    cout<<max_num;
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/min-num-of-jumps/submissions
# 풀이
도착한 지점의 점프가능 횟수만큼 for문을 돌면서 가능한 경우의 수를 모두 계산한다.
# 코드
```
#include <iostream>
using namespace std;

#define MAX 10
int n;
int arr[MAX];
int cnt=0;
int min_num =100;

void Check(int num){
    if(num==n-1){
        min_num = min(min_num,cnt);
    }
    for(int i=1; i<=arr[num]; i++){
        cnt+=1;
        Check(num+i);
        cnt-=1;
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Check(0);
    if(min_num!=100)
        cout<<min_num<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/n-choose-m/submissions
# 풀이
벡터에 넣는 조건을 추가해주어서 오름차순, 중복되지않게 벡터에 담는다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int>v;

void Print(){
    for(int i=0; i<m; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==m){
        Print();
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(v.empty()||v.back()<i){
            v.push_back(i);
            Check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>n>>m;
    Check(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/choose-m-out-of-n-points/submissions
# 풀이
배열에 넣어 거리를 계산하는데 중복되는 부분이 있어 이를 시작점, 그리고 방문했는지 확인하는 배열로 중복 체크하였다.  
방문 체크 배열이 필요 없다. 시작점을 함수 인자로 넘겨주면 해결된다.
# 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

#define MAX 20

vector<pair<int,int>>v;
vector<pair<int,int>>w;
double ans = 10000000;
int n,m;

double Dist(){
    double dist_max = 0;
    for(int i=0; i<m; i++){
        int x1 = w[i].first;
        int y1 = w[i].second;
        for(int j=i+1; j<m; j++){
            int x2 = w[j].first;
            int y2 = w[j].second;
            dist_max = max(pow(x2-x1,2)+pow(y2-y1,2),dist_max);
        }
    }
    return dist_max;
}

void Check(int num, int start){
    if(num==m){
        ans = min(ans, Dist());
        return;
    }

    for(int i=start; i<n; i++){
            w.push_back({v[i].first, v[i].second});
            Check(num+1, i+1);
            w.pop_back();
    }
}

int main() {

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    Check(0,0);
    cout<<ans;

    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/n-permutation/introduction
# 풀이
방문했는지 아닌지 bool 배열을 이용해서 확인한다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 8
int n;
vector<int> v;
bool visited[MAX];

void Print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Check(int num){
    if(num==n){
        Print();
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            Check(num+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin>>n;
    Check(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/backward-permutation/submissions
# 풀이
역순으로 출력해야 하므로 for문을 반대로 작성하면 된다.
# 코드
```
#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

vector<int> v;
bool visited[MAX];
int n;

void Print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void Chechk(int num){
    if(num==n)
        Print();
    
    for(int i=n; i>0; i--){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            Chechk(num+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    cin>>n;
    Chechk(0);
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/max-sum-of-numbers/submissions
# 풀이
각 행에서 열을 선택하는 방법을 이용해서 행마다 다른 열을 선택하도록 Backtracking을 사용한다.  
최댓값을 계산할 때는 열을 담은 벡터를 이용해서 계산한다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 11
int n;
int arr[MAX][MAX];
bool visited[MAX];
vector<int> v;
int max_num=0;

void Check(int num){
    if(num==n){
        int sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i][v[i]];
        }
        max_num = max(max_num, sum);
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            
            Check(num+1);

            visited[i]=false;
            v.pop_back();
        }
    }
}


int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    Check(0);
    cout<<max_num<<'\n';
    return 0;
}
```

# 문제
https://inha.codetree.ai/missions/2/problems/maximin-of-numbers/submissions
# 풀이
행마다 선택하는 열을 고르는데 중복된 열을 고르지않기 위해서 bool 배열을 이용한다.
# 코드
```
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

#define MAX 11

int n;
int arr[MAX][MAX];
bool visited[MAX];
vector<int> v;
int max_num = 0;

int Min_num(){
    int num = INT_MAX;
    for(int i=0; i<n; i++){
        if(num>v[i]){
            num = v[i];
        }
    }
    return num;
}

void Chechk(int num){
    if(num==n){
        max_num = max(max_num, Min_num());
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(arr[num][i]);
            Chechk(num+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    Chechk(0);
    cout<<max_num;
    return 0;
}
```
