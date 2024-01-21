#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool alpha[26];
vector<string> v;
int ans = 0;
void dfs(int idx, int k){
    if(k==0){
        int cnt = 0;
        for(string elem : v){
            bool sw = true;
            for(char word : elem){
                if(!alpha[word-'a']){
                    sw = false;
                    break;
                }
            }
            if(sw) cnt++;
        }
        ans = max(ans,cnt);
    }

    for(int i= idx; i<26; i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        dfs(i, k-1);
        alpha[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;


    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s.substr(4, s.length()-8));
    }

    if(k<5){
        cout<<0<<'\n';
        return 0;
    }
    alpha[0] = true; alpha[2] = true; alpha[8] = true; alpha[13] = true; alpha[19] = true;

    dfs(0, k-5);
    cout<<ans<<'\n';
  
}
