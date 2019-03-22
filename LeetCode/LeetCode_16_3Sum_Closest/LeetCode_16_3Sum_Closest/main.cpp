//
//  main.cpp
//  LeetCode_16_3Sum_Closest
//
//  Created by 舒毅文 on 2019/3/22.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 暴力求解法
 */
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int temp = nums[i] + nums[j] + nums[k];
                    if (abs(res - target) > abs(target - temp)) {
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};


/*
 先排序
 然后使用双指针
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int temp = nums[i] + nums[left] + nums[right];
                if (abs(res - target) > abs(target - temp)) {
                    res = temp;
                }
                if (temp < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    // [-1,2,1,-4]
    Solution * aaa = new Solution();
    vector<int> bbb = {-1, 2, 1, -4};
    int ccc = aaa->threeSumClosest(bbb, 1);
    std::cout << "Hello, World!\n";
    return 0;
}
