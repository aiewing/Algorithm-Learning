//
//  main.cpp
//  LeetCode_27_Remove_Element
//
//  Created by 舒毅文 on 2019/3/29.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 双指针法
 左边找等于val 右边找不等与val
 交换
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int res = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] == val && nums[right] != val) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
                res++;
            } else if (nums[left] != val) {
                left++;
            }  else if (nums[right] == val) {
                right--;
                res++;
            }
        }
        cout << "";
        return n - res;
    }
};


int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<int> bbb = {1};
    int ccc = aaa->removeElement(bbb, 1);
    return 0;
}
