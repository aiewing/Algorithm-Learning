//
//  main.cpp
//  LeetCode_647_Palindromic_Substrings
//
//  Created by 舒毅文 on 2019/3/11.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 暴力求解
 遍历每一个数字串，以这个字符串为中心，判断是否回文字符串
 */
class Solution1 {
public:
    int countSubstrings(string s) {
        int count = s.size();
        if (count == 0) {
            return 0;
        } else if (count == 1) {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < count - 1; i++) {
            int a = calculateCount(s, i, i, count - 1);
            int b = calculateCount(s, i, i + 1, count - 1);
            res += (a + b);
        }
        return ++res;
    }
    
    int calculateCount(string s, int left, int right, int max) {
        int res = 0;
        while (left >= 0 && right <= max) {
            if (s[left--] == s[right++]) {
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};

/*
 动态规划
 */
class Solution {
public:
    int countSubstrings(string s) {
        int count = s.size();
        int res = 0;
        vector<vector<bool>> dp(count, vector<bool>(count, false));

        for (int i = count - 1; i >= 0; i--) {
            for (int j = count - 1; j >= i; j--) {
                if (s[i] == s[j] && ((j - i) <= 2 || dp[i + 1][j - 1]) ) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution * aa = new Solution();
    int res = aa->countSubstrings("fdsklf");
    std::cout << "Hello, World!\n";
    return 0;
}
