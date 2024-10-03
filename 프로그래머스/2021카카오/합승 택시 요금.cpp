#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int Map[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            Map[i][j] = INT_MAX;
        }
        Map[i][i] = 0;
    }

    for(int i=0; i<fares.size(); i++){
        int A = fares[i][0];
        int B = fares[i][1];
        int coin = fares[i][2];
        
        Map[A][B] = coin;
        Map[B][A] = coin;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(Map[i][k]!=INT_MAX&&Map[k][j]!=INT_MAX)
                    Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
            }
        }
    }
    
    int answer = Map[s][a] + Map[s][b];
    
    
    for(int i=1; i<=n; i++){
        if(i!=s){
            answer = min(answer, Map[s][i] + Map[i][a] + Map[i][b]);
        }
    }
    
    return answer;
}
