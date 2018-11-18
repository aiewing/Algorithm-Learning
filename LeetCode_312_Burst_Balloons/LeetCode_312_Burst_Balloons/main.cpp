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

// 题目
/*
 Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
 
 Find the maximum coins you can collect by bursting the balloons wisely.
 
 Note:
 
 You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 Example:
 
 Input: [3,1,5,8]
 Output: 167
 Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */


// 解析
/*
 现在我们自定义一组气球，括号内是虚拟的数字
 
 （1）1 3 6 2 9 7 8 5 4（1）
 如果一个个的去戳破，那到最后留下来的是9号的气球。（过程先不列举）
 
 现在我们使用逆向思考的方式
 如果我们现在已知最后一个被戳破的是9号气球，那最后一个就是（1）9（1）
 
 9号球的左边：（1）1 3 6 2（9）
 9号球的右边：（9）7 8 5 4（1）
 上面两个数组就是可以相互独立的存在，那就又可以回到原始的那个问题了
 
 下面使用参数来表示这个流程
 
 left 3 1 5 … mid …  4 9 7 right
 
 总的最多可以得到的是：dp[left, right]
 最后一个被戳破的是mid：arr[left - 1] * arr[mid] * arr[right + 1]
 左边的部分是：dp[left, mid - 1]
 右边的部分是：dp[mid + 1, right]
 
 总结上面的可以得到递推公式：总的获得量 = 左边的独立部分 + 最后被戳破的 + 右边的独立部分
 dp[left, right] = dp[left, mid - 1] + arr[left - 1] * arr[mid] * arr[right + 1] + dp[mid + 1, right]
 
 优化过后的递推公式：应该比较之后取最大值
 dp[left, right] = max(dp[left, right], dp[left, mid - 1] + arr[left - 1] * arr[mid] * arr[right + 1] + dp[mid + 1, right])
 */

// DP解
// 时间复杂度：O(n^3)
// 空间复杂度：O(n^2)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        // 先创建一个新的数组 把原来的数据前后都加上1 方便计算
        vector<int> arr;
        arr.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]);
        }
        arr.push_back(1);

        // 构建一个二维数组 存放DP元素
        long n = arr.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n);
        }
        
        // 从DP的推导公式来看 我们需要3个参数 left right mid
        // 但是我们需要从下向上推 所以需要引入一个len的量 一直变大len来慢慢的自下向上递进
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int mid = left + 1; mid < right; mid++) {
                    dp[left][right] = max(dp[left][right], (arr[left] * arr[mid] * arr[right] + dp[left][mid] + dp[mid][right]));
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
