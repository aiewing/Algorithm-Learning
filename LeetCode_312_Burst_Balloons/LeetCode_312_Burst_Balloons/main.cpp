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
class Solution1 {
public:
    int maxCoins(vector<int>& nums) {
        long count = nums.size();
        // 先找到一个乘积最大的数 然后去掉一个其中最小的数
        int maxPro = 0;
        int product = 0;
        int maxSelectIndex = 0;
        int minIndex = 0;
        for (int i = 0; i < count; i++) {
            if (i == 0) {
                product = nums[i] * nums[i + 1];
            } else if (i == count - 1) {
                product = nums[i] * nums[i - 1];
            } else {
                product = nums[i] * nums[i + 1] * nums[i - 1];
            }
            if (product > maxPro) {
                maxSelectIndex = i;
                maxPro = product;
            }
        }
        
        // 开始去除一个最小的数字
        if (maxSelectIndex == 0) {
            
        }
        
        
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> num = {3,1,5,8};
    Solution1 * so = new Solution1();
    int res = so->maxCoins(num);
    cout << res << endl;
    return 0;
}
