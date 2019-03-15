//
//  main.cpp
//  LeetCode_740_Delete_and_Earn
//
//  Created by 舒毅文 on 2019/3/15.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 先把所有的数都存起来
 如果dp[i]代表的是获得点数的总和
 如果我选择了i，那么dp[i] = dp[i - 2] + i * (i的个数)
 如果不选i，那么dp[i] = dp[i - 1]
 */
class Solution1 {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<int> dp(10001, 0);
        dp[1] = count[1];
        for (int i = 2; i < 10000; i++) {
            dp[i] = max(dp[i - 1], (dp[i - 2] + i * count[i]));
        }
        return dp[10000];
    }
};

/*
 优化内存
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        int maxNum = 2;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            maxNum = max(maxNum, nums[i]);
        }
        vector<int> dp(maxNum + 1, 0);
        dp[1] = count[1];
        for (int i = 2; i < maxNum + 1; i++) {
            dp[i] = max(dp[i - 1], (dp[i - 2] + i * count[i]));
        }
        std::cout << "Hello, World!\n";
        return dp[maxNum];
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    vector<int> aaa = {3, 4, 2};
    int a = aa->deleteAndEarn(aaa);
    std::cout << "Hello, World!\n";
    return 0;
}
