#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> card;
    int n;
    int answer = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        card.push(-x);
    }

    while(card.size()>1){
        int y = -card.top();
        card.pop();
        int z = -card.top();
        card.pop();
        
        answer += (y+z);

        card.push(-(y+z));
    }

    cout<<answer<<'\n';
}

