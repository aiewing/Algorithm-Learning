//
//  main.cpp
//  LeetCode_53_Maximum_Subarray
//
//  Created by 舒毅文 on 2018/11/16.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

/*
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 Example:
 
 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 */

/*
  推导递推公式
如果是之前的dp中的总和大于零，那就加上x当前的数字，如果总和小于零，那就舍弃之前的总和，直接加0
dp[i] = arr[i] + max(dp[i - 1], 0)
 
 */

/*
 时间复杂度：O(n)
 空间复杂度：O(n)
 */
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        long count = nums.size();
        vector<int> dp(count);
        dp[0] = nums[0];
        int maxSum = dp[0];
        
        for (int i = 1; i < count; i++) {
            dp[i] = nums[i] + max(dp[i - 1], 0);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
    
    int divide(vector<int>& nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        if (low == high - 1) {
            return max(nums[low] + nums[high], max(nums[low], nums[high]));
        }
        int mid = (low + high) / 2;
        int leftMax = divide(nums, low, mid - 1);
        int rightMax = divide(nums, mid + 1, high);
        int midMax = nums[mid];
        int temp = midMax;
        
        for (int i = mid - 1; i >= low; i--) {
            temp += nums[i];
            if (temp > midMax) {
                midMax = temp;
            }
        }
        temp = midMax;
        
        for (int i = mid + 1; i <= high; i++) {
            temp += nums[i];
            if (temp > midMax) {
                midMax = temp;
            }
        }
        return max(midMax, max(leftMax, rightMax));
    }
};

int main(int argc, const char * argv[]) {
    Solution *so = new Solution();
    vector<int> aa = {-2,1,-3,4,-1,2,1,-5,4};
    int res = so->maxSubArray(aa);
    
    printf("");
    return 0;
}
