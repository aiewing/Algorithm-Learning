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
        vector<int> dp(count + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < count; i++) {
            dp[i] = dp[i - 1] + \
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
