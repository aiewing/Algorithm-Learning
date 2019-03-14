//
//  main.cpp
//  LeetCode_713_Subarray_Product_Less_Than_K
//
//  Created by 舒毅文 on 2019/3/14.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 超时
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = nums.size();
        if (count == 0) {
            return 0;
        }
        int res = 0;
        vector<int> dp(count + 1, 0);
        if (k > nums[0]) {
            dp[0] = 1;
        }
        for (int i = 1; i < count; i++) {
            dp[i] = dp[i - 1] + calculate(nums, k, i);
        }
        cout << "Hello, World!\n";
        return dp[count - 1];
    }
    
    int calculate(vector<int>& nums, int k, int index) {
        int res = 0;
        int sub = 1;
        for (int i = index; i >= 0; i--) {
            sub *= nums[i];
            if (k > sub) {
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution * aa = new Solution();
    vector<int> bb = {10, 5, 2, 6};
    int a = aa->numSubarrayProductLessThanK(bb, 100);
    std::cout << "Hello, World!\n";
    return 0;
}
