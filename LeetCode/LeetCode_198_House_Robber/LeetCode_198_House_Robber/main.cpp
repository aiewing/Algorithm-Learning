//
//  main.cpp
//  LeetCode_198_House_Robber
//
//  Created by Aiewing on 2019/3/10.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int count = nums.size();
        if (count == 0) {
            return 0;
        } else if (count == 1) {
            return nums[0];
        } else if (count == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(count + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < count; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[count - 1];
    }
};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        nums.push_back(0);
        nums.push_back(0);
        nums.push_back(0);
        int count = nums.size();
        vector<int> dp(count + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < count; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[count - 3];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
