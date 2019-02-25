//
//  main.cpp
//  LeetCode_322_Coin_Change
//
//  Created by 舒毅文 on 2019/2/25.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 如果硬币的价值总和是F(x),当前放进去的硬币的价值是f（x），那么F（x）= F（x - 1） + f（x）
 dp[i] = dp[i - coins[j]] + 1
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        if (n == 0 || amount == 0) {
            return 0;
        }
        sort(coins.begin(), coins.end());
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size() && coins[j] <= i; j++) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
