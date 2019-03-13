//
//  main.cpp
//  LeetCode_712_Minimun_ASCII_Delete_Sum_for_Two_Strings
//
//  Created by 舒毅文 on 2019/3/13.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 对比两个字符串
 dp[i][j]代表当前需要删除的，dp[0][0]代表两个字符串都为空
 如果s1[i]和s2[j]相同，那就代表不需要删除，dp[i][j] = dp[i - 1][j - 1]
 如果s1[i]和s2[j]不同，那就代表需要删除，dp[i][j] = min(dp[i][j - 1] - s1[i], dp[i - 1][j] - s2[j])
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min((dp[i][j - 1] + s2[j - 1]), (dp[i - 1][j] + s1[i - 1]));
                }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
