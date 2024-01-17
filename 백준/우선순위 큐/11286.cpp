#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    priority_queue<pair<int,int>> pq;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a==0){
            if(pq.size()==0)
                cout<<0<<'\n';
            else{
                if(pq.top().second==1)
                    cout<<pq.top().first<<'\n';
                else
                    cout<<-pq.top().first<<'\n';
                pq.pop();
            }
        }
        else{
            if(a>0)
                pq.push(make_pair(-a,-1));
            else
                pq.push(make_pair(a,1));
        }
    }
}
