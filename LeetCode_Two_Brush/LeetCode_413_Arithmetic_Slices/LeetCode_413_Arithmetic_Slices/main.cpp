//
//  main.cpp
//  LeetCode_413_Arithmetic_Slices
//
//  Created by 舒毅文 on 2019/3/21.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 DP解
 */
class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return 0;
        }
        vector<vector<bool>> dp(n - 2, vector<bool>(n, false));
        for (int i = 0; i < n - 2; i++) {
            dp[i][i + 1] = true;
        }
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                // 判断当前是否为等差数列
                if ((A[j] - A[j - 1]) == (A[j - 1] - A[j - 2]) && dp[i][j - 1]) {
                    dp[i][j] = true;
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

/*
 DP解+优化
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                // 判断当前是否为等差数列
                if ((A[j] - A[j - 1]) == (A[j - 1] - A[j - 2])) {
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *aaa = new Solution();
    vector<int> bbb = {1, 2, 3, 4};
    int ccc = aaa->numberOfArithmeticSlices(bbb);
    std::cout << "Hello, World!\n";
    return 0;
}
