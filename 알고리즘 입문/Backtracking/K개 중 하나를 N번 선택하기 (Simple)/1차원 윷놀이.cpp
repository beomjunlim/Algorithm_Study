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
