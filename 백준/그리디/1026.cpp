#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 50
int A[MAX];
int B[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    for(int i=0; i<n; i++){
        cin>>B[i];
    }

    sort(A, A+n);
    sort(B, B+n, greater<>());

    int answer = 0;

    for(int i=0; i<n; i++){
        answer += A[i]*B[i];
    }

    cout<<answer<<'\n';
}

