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
 dp[i] = dp[i - 1] + (和s[i]有关的字符串都遍历一次的回文字符串的总和)
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

/*
 昨天说的dp是，dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1],这个意思是从中间向两边扩展，我在想，那我直接i置0，那就可以直接从左往右了么？dp[0][j] = dp[0][j - 1] + dp[1][j] - dp[1][j - 1]
 */

int main(int argc, const char * argv[]) {
    
    Solution * aa = new Solution();
    int res = aa->countSubstrings("fdsklf");
    std::cout << "Hello, World!\n";
    return 0;
}
