#include <string>
#include <vector>

using namespace std;

bool canCarryInTime(long long time, int gold, int silver, vector<int>g, vector<int>s, vector<int>w, vector<int>t){
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalWeight = 0;
    
    for(int i=0; i<w.size(); i++){
        long long trips = time / (t[i]*2);
        if(time % (t[i]*2)>=t[i])
            trips++;
        
        long long maxGold = min(trips*w[i], (long long)g[i]);
        long long maxSilver = min(trips*w[i], (long long)s[i]);
        long long maxWeight = min(trips*w[i], (long long)g[i] + s[i]);
        
        totalGold += maxGold;
        totalSilver += maxSilver;
        totalWeight += maxWeight;
        
        if(totalGold>=gold&&totalSilver>=silver&&totalWeight>=(gold + silver))
            return true;
    }
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    long long left = 0;
    long long right = 1e9*2*1e5*2;

    while(left<right){
        long long mid = (left + right) / 2;
        
        if(canCarryInTime(mid, a, b, g, s, w, t))
            right = mid;
        else
            left = mid + 1;
    }
    answer = left;
    return answer;
}
