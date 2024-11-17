#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int dp[101][1001];
        int W[101];
		int V[101];
        int n,k;
        cin>>n>>k;
        for(int i=1; i<=n; i++){
            cin>>W[i]>>V[i];
        }
        

        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                if(W[i]<=j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        
        cout<<"#"<<test_case<<" "<<dp[n][k]<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
