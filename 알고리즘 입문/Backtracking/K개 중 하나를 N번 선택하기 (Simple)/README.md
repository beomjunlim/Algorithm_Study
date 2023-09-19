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
