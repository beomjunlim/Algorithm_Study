#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Pair{
    int first;
    int second;
};

Pair arr[26];
bool bingo[5][5];

bool myfunction(){
    int cnt = 0;
    for(int i=0; i<5; i++){
        if(bingo[i][0]&&bingo[i][1]&&bingo[i][2]&&bingo[i][3]&&bingo[i][4])
            cnt++;
        if(bingo[0][i]&&bingo[1][i]&&bingo[2][i]&&bingo[3][i]&&bingo[4][i])
            cnt++;
    }

    if(bingo[0][0]&&bingo[1][1]&&bingo[2][2]&&bingo[3][3]&&bingo[4][4])
        cnt++;
    
    if(bingo[0][4]&&bingo[1][3]&&bingo[2][2]&&bingo[3][1]&&bingo[4][0])
        cnt++;

    if(cnt>=3)
        return true;
    else
        return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool sw;
    int num;
    int answer = 0;
    int cnt = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>num;
            arr[num] = {i,j};
        }
    }


    for(int i=1; i<=25; i++){
        cin>>num;
        bingo[arr[num].first][arr[num].second] = true;
        if(myfunction()){
            answer = i;
            break;
        }
    }
    cout<<answer<<'\n';
}

