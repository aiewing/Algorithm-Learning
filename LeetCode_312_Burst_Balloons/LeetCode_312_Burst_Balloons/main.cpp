//
//  main.cpp
//  LeetCode_312_Burst_Balloons
//
//  Created by 舒毅文 on 2018/11/12.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include "vector"

using namespace std;

// brute-force
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        // 先创建一个新的数组
        vector<int> arr;
        arr.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]);
        }
        arr.push_back(1);

        int n = arr.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n);
        }
        
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int m = left + 1; m < right; m++) {
                    dp[left][right] = max(dp[left][right], (arr[left] * arr[m] * arr[right] + dp[left][m] + dp[m][right]));
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main(int argc, const char * argv[]) {

    vector<int> num = {3,1,5,8};
    Solution * so = new Solution();
    int res = so->maxCoins(num);
    cout << res << endl;
    return 0;
}
