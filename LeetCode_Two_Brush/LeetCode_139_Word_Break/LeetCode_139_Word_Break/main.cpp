//
//  main.cpp
//  LeetCode_139_Word_Break
//
//  Created by 舒毅文 on 2019/3/20.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // 保存上一个DP为true的位置
        int index = 0;
        // 计算字符串最大长度
        int strMax = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            strMax = max(strMax, (int)wordDict[i].length());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = index; j >= (i - strMax) && j >= 0; j--) {
                string subStr = s.substr(j, i - j);
                if (aiewing(subStr, wordDict) && dp[j]) {
                    dp[i] = true;
                    index = i;
                    break;
                }
            }
        }
        std::cout << "Hello, World!\n";
        return dp[n];
    }
    
    bool aiewing(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            if (s == wordDict[i]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<string> bbb = {"leet", "code"};
    string ccc = "leetcode";
    bool ddd = aaa->wordBreak(ccc, bbb);
    std::cout << "Hello, World!\n";
    return 0;
}
