#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    string str, bomb;
    cin >> str >> bomb;

    
    vector<char> word;

    for (int i = 0; i < str.length(); i++) {
        word.push_back(str[i]);

        if (word.size() >= bomb.length()) {
            bool sw = true;
            for (int j = 0; j < bomb.length(); j++) {
                if (word[word.size() - bomb.length() + j] != bomb[j]) {
                    sw = false;
                    break;
                }
            }

            if (sw) {
                for (int j = 0; j < bomb.length(); j++) {
                    word.pop_back();
                }
            }
        }
    }

    if (word.empty())
        cout << "FRULA";
    else {
        for (int i = 0; i < word.size(); i++)
            cout << word[i];
    }
    return 0;
}
