//
//  main.cpp
//  LeetCode_357_Count_Numbers_with_Unique_Digits
//
//  Created by 舒毅文 on 2019/3/15.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 dp[i] = dp[i - 1] +
 
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        vector<int> dp(n + 2, 1);
        dp[1] = 10;
        for (int i = 2; i <= n && i <= 10; i++) {
            dp[i] = dp[i - 1] + aie(i);
        }
        return dp[n];
    }
    
    int aie(int n) {
        int sum = 9;
        for (int i = 1; i < n; i++) {
            sum *= (10 - i);
        }
        std::cout << "Hello, World!\n";
        return sum;
    }
};



int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    int a = aa->countNumbersWithUniqueDigits(2);
    std::cout << "Hello, World!\n";
    return 0;
}
