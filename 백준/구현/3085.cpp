#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 50
int n;
int ans = 0;
char arr[MAX][MAX];

void findCandy(){
    int num = 0;
    for(int i=0; i<n; i++){
        num = 1;
        for(int j=0; j<n-1; j++){
            if(arr[i][j]==arr[i][j+1]){
                num++;
            }
            else{
                ans = max(ans,num);
                num = 1;
            }
        }
        ans = max(ans, num);
    }

    for(int i=0; i<n; i++){
        num = 1;
        for(int j=0; j<n-1; j++){
            if(arr[j][i]==arr[j+1][i]){
                num++;
            }
            else{
                ans = max(ans,num);
                num = 1;
            }
        }
        ans = max(ans, num);
    }
}

void findColumn(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arr[i][j]!=arr[i][j+1]){
                swap(arr[i][j], arr[i][j+1]);
                findCandy();
                swap(arr[i][j], arr[i][j+1]);
            }
            if(arr[j][i]!=arr[j+1][i]){
                swap(arr[j][i], arr[j+1][i]);
                findCandy();
                swap(arr[j][i], arr[j+1][i]);
            }
        }
    }

    cout<<ans<<'\n';
}
