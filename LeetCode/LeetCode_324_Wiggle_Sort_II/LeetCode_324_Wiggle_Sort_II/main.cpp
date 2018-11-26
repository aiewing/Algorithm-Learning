//
//  main.cpp
//  LeetCode_324_Wiggle_Sort_II
//
//  Created by Aiewing on 2018/11/22.
//  Copyright © 2018 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


// 题目
/*
 Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 
 Example 1:
 
 Input: nums = [1, 5, 1, 1, 6, 4]
 Output: One possible answer is [1, 4, 1, 5, 1, 6].
 Example 2:
 
 Input: nums = [1, 3, 2, 2, 3, 1]
 Output: One possible answer is [2, 3, 1, 3, 1, 2].
 Note:
 You may assume all input has valid answer.
 
 Follow Up:
 Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int small = (nums.size() - 1) / 2;
        int large = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 ==0) {
                nums[i] = temp[small--];
            } else {
                nums[i] = temp[large--];
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *so = new Solution();
    vector<int> aa = {1, 5, 2, 3, 6, 4};
    so->wiggleSort(aa);
            for_each(aa.begin(), aa.end(), [](int a) {
                cout << a << endl;
            });
    return 0;
}
