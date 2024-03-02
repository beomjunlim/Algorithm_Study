#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;
    cin>>t;

    while(t>0){
        cin>>k;
        multiset<int> ms;

        for(int i=0; i<k; i++){
            char cmd;
            int num;
            cin>>cmd>>num;

            if(cmd=='I')
                ms.insert(num);
            else{
                if(!ms.empty()){
                    if(num==-1)
                        ms.erase(ms.begin());
                    else{
                        auto it = ms.end();
                        it--;
                        ms.erase(it);
                    }
                }
            }
        }

        if(ms.empty())
            cout<<"EMPTY"<<'\n';

        else{
            auto end = ms.end();
            end--;
            cout<<*end<<" "<<*ms.begin()<<'\n';
        }

        t--;
    }
}

