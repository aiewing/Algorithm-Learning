//
//  main.cpp
//  LeetCode_139_Word_Break
//
//  Created by 舒毅文 on 2019/3/18.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (dp[j] && aiewing(sub, wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    bool aiewing(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            if (wordDict[i] == s) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
