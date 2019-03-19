//
//  main.cpp
//  LeetCode_75_Sort_Colors
//
//  Created by 舒毅文 on 2019/3/19.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 两个遍历解
 */
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            if (nums[i] == 0) {
                red++;
            } else if (nums[i] == 1) {
                white++;
            } else {
                blue++;
            }
        }
        for (int i = 0; i < count; i++) {
            if (i < red) {
                nums[i] = 0;
            } else if (i < red + white) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }
};

/*
 一个遍历解
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {
            while (left < right) {
                if (nums[i] == 0 && i > left) {
                    aie(nums, i, left++);
                } else if (nums[i] == 2 && i < right) {
                    aie(nums, i, right--);
                } else {
                    break;
                }
            }
        }
    }
    
    void aie(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *aaa = new Solution();
    vector<int> aa = {0, 1, 2};
    aaa->sortColors(aa);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
