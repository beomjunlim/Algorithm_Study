#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<climits>
using namespace std;

#define MAX 11

int arr[MAX];    
int n;
vector<int> v;

void myFunction(int index, int ans, int plus, int minus, int product, int divide){
    if(index==n){
        v.push_back(ans);
        return;
    }

    if(plus>0){
        int num = ans + arr[index];
        myFunction(index+1,num,plus-1,minus,product,divide);
    }
    if(minus>0){
        int num = ans - arr[index];
        myFunction(index+1,num,plus,minus-1,product,divide);
    }
    if(product>0){
        int num = ans * arr[index];
        myFunction(index+1,num,plus,minus,product-1,divide);
    }
    if(divide>0){
        int num = ans / arr[index];
        myFunction(index+1,num,plus,minus,product,divide-1);
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int plus, minus, product, divide;
    cin>>plus>>minus>>product>>divide;

    int min_num = INT_MAX;
    int max_num = INT_MIN;

    myFunction(1, arr[0], plus, minus, product, divide);

    sort(v.begin(), v.end());
    cout<<v[v.size()-1]<<" "<<v[0]<<'\n';
}
