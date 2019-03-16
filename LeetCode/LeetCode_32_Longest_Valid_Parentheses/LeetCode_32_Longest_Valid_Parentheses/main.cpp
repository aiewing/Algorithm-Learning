//
//  main.cpp
//  LeetCode_32_Longest_Valid_Parentheses
//
//  Created by Aiewing on 2019/3/15.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
    int longestValidParentheses(string s) {
        int count = s.size();
        int res = 0;
        vector<int> aa(count, 0);
        vector<int> bb;
        for (int i = 0; i < count; i++) {
            char ch = s[i];
            // 先判断
            if (bb.size() == 0 || bb.back() > 1000000) {
                // 入栈
                if (ch == '(') {
                    bb.push_back(i);
                } else {
                    bb.push_back(i + 1000000);
                }
            } else {
                if (ch == '(') {
                    // 入栈
                    bb.push_back(i);
                } else {
                    // 出栈
                    aa[bb.back()] = 1;
                    aa[i] = 1;
                    bb.pop_back();
                }
            }
        }
        int max = 0;
        for (int i = 0; i < aa.size(); i++) {
            if (aa[i] == 1) {
                max++;
                res = std::max(res, max);
            } else {
                max = 0;
            }
        }
        
        std::cout << "Hello, World!\n";
        return res;
    }
};


/*
 DP解
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        s = ')' + s;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1 - dp[i - 1]] == '(') {
                    dp[i] = dp[i - 1] + 2;
                }
                dp[i] += dp[i - dp[i]];
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution *aaa = new Solution();
    int a = aaa->longestValidParentheses(")()())");
    std::cout << "Hello, World!\n";
    return 0;
}
