//
//  main.cpp
//  LeetCode_303_Range_Sum_Query_Immutable
//
//  Created by Aiewing on 2019/3/10.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> arr;
    vector<int> dp;
    NumArray(vector<int> nums) {
        arr = nums;
        vector<int> aie(nums.size(), INT_MIN);
        dp = aie;
    }
    
    int sumRange(int i, int j) {
        if (j == 0) {
            return arr[0];
        }
        if (dp[j] == INT_MIN) {
            // 需要重新计算总和
            calculate(j);
        }
        if (i == 0) {
            return dp[j];
        } else {
            return dp[j] - dp[i - 1];
        }
        return 0;
    }
    
    int calculate(int i) {
        if (i == 0) {
            dp[i] = arr[0];
            return arr[0];
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }
        cout << arr[i] << endl;
        int res = calculate(i - 1) + arr[i];
        dp[i] = res;
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> aie = {-8665,9669,292,-327,-9892,-1808,-6069,-4366};
    NumArray * arr = new NumArray(aie);
    long long aa = arr->sumRange(0, 0);
    cout << aa;
    return 0;
}
