#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }

    vector<int> dp_front; 
    vector<int> dp_back;  
    vector<int> front_cnt(N, 1);
    vector<int> back_cnt(N, 1); 

    dp_front.push_back(arr[0]);
    for (int i = 0; i < N; i++) {
        if(arr[i]>dp_front.back())
            dp_front.push_back(arr[i]);
        else{
            auto it = lower_bound(dp_front.begin(), dp_front.end(), arr[i]);
            *it = arr[i];
        }

        front_cnt[i] = dp_front.size();
    }

    reverse(arr.begin(), arr.end());
    dp_back.push_back(arr[0]);
    for (int i = 0; i < N; ++i) {
        if(arr[i]>dp_back.back())
            dp_back.push_back(arr[i]);
        else{
            auto it = lower_bound(dp_back.begin(), dp_back.end(), arr[i]);
            *it = arr[i];
        }

        back_cnt[N - i - 1] = dp_back.size();
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, front_cnt[i] + back_cnt[i]);
    }

    cout << ans - 1 << endl;
    return 0;
}
