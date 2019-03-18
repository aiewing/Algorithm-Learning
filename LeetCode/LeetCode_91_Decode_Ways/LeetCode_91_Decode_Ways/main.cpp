//
//  main.cpp
//  LeetCode_91_Decode_Ways
//
//  Created by 舒毅文 on 2019/3/18.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 DP解
 如果dp[i]代表当前字符串下的解码方法的总数，那和爬楼梯一样
 dp[i] = dp[i - 1] + dp[i - 2]
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            int temp = atoi(s.substr(i - 1, 2).c_str());
            if (temp >= 10 && temp <= 26) {
                dp[i + 1] += dp[i - 1];
            } else if (temp % 10 == 0) {
                return 0;
            }
            if (temp % 10 != 0) {
                dp[i + 1] += dp[i];
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    int a = aaa->numDecodings("130");
    std::cout << "Hello, World!\n";
    return 0;
}
