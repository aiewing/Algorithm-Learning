//
//  main.cpp
//  LeetCode_55_Jump_Game
//
//  Created by 舒毅文 on 2019/2/28.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxNum = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            if (maxNum >= count - 1) {
                return true;
            } else {
                if (nums[i] == 0 && maxNum <= i) {
                    return false;
                }
                maxNum = max(maxNum, i + nums[i]);
            }
        }
        if (maxNum >= count - 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
