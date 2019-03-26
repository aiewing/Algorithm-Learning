//
//  main.cpp
//  LeetCode_41_First_Missing_Positive
//
//  Created by 舒毅文 on 2019/3/26.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
解题思路：
 数组的第i位放i数字
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        for (int index = 0; index < n; index++) {
            while (nums[index] > 0 && nums[index] <= n && nums[index] != index + 1 && nums[index] != nums[nums[index] - 1]) {
                // 归位
                int temp = nums[index];
                nums[index] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
            
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<int> bbb = {1, 1};
    int ccc = aaa->firstMissingPositive(bbb);
    std::cout << "Hello, World!\n";
    return 0;
}
