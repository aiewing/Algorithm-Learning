//
//  main.cpp
//  LeetCode_746_Min_Cost_Climbing_Stairs
//
//  Created by 舒毅文 on 2019/3/1.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int count = cost.size();
        vector<int> dp(count + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < count; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[count - 1], dp[count - 2]);
    }
};


class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int count = cost.size();
        int a = cost[0];
        int b = cost[1];
        int c;
        for (int i = 2; i < count; i++) {
            c = min(a, b) + cost[i];
            a = b;
            b = c;
        }
        return min(a, b);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
