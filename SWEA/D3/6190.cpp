#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int ans = -1;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
        	int num;
            cin>>num;
            v.push_back(num);
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int num = v[i]*v[j];
                string str = to_string(num);
                bool sw = true;
                
                for(int k=0; k<str.length()-1; k++){
                	if(str[k]-'0'>str[k+1]-'0'){
                    	sw = false;
                        break;
                    }
                }
                
                if(sw){
                    ans = max(ans, num);
                }
            }
        }
        
        cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;
}
