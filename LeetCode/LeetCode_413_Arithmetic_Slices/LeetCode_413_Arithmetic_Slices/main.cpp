//
//  main.cpp
//  LeetCode_413_Arithmetic_Slices
//
//  Created by 舒毅文 on 2019/3/13.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 暴力求解
 */
class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = A.size();
        if (count < 3) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < count - 2; i++) {
            int a = calculate(A, i, count);
            res += a;
        }
        return res;
    }
    
    int calculate(vector<int>& A, int left, int count) {
        int res = 0;
        int a = A[left + 1] - A[left];
        for (int i = left + 1; i < count - 1; i++) {
            if ((A[i + 1] - A[i]) == a) {
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};


/*
 DP求解 这种DP和上面的解法差不多，感觉有很大问题
 */
class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = A.size();
        if (count < 3) {
            return 0;
        }
        int res = 0;
        vector<vector<bool>> dp(count, vector<bool>(count, false));
        for (int i = 0; i < count - 2; i++) {
            for (int j = i + 2; j < count; j++) {
                if ((j == i + 2 || dp[i][j - 1]) && (A[j] - A[j - 1]) == (A[j - 1] - A[j - 2])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};


/*
 如果以A[i]为尾巴的等差数列为dp[i], 那么dpi] = dp[i - 1] + 1;
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = A.size();
        if (count < 3) {
            return 0;
        }
        int res = 0;
        vector<int> dp(count, 0);
        for (int i = 2; i < count; i++) {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
                dp[i] = dp[i - 1] + 1;
            }
            res += dp[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
