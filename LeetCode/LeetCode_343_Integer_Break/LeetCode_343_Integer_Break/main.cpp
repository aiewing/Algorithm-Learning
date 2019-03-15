//
//  main.cpp
//  LeetCode_343_Integer_Break
//
//  Created by 舒毅文 on 2019/3/14.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 dp解
 dp[i] = max(dp[i], dp[j] * (i - j))
 */
class Solution {
public:
    vector<int> res;
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(j * (i - j), max(dp[i], dp[j] * (i - j)));
            }
        }
        std::cout << "Hello, World!\n";
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    int a = aa->integerBreak(10);
    std::cout << "Hello, World!\n";
    return 0;
}
