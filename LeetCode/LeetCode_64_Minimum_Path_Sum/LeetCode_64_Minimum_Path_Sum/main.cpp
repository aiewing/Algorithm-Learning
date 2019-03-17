//
//  main.cpp
//  LeetCode_64_Minimum_Path_Sum
//
//  Created by Aiewing on 2019/3/17.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 DP解
 dp[i][j] = dp[i - 1][j] + grid[i][j]
 dp[i][j] = dp[i][j - 1] + grid[i][j]
 */
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = 0;
        if (m > 0) {
            n = (int)grid.front().size();
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> aa = grid.front();
        if (m > 0 && n > 0) {
            dp[0][0] = grid[0][0];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};



int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<vector<int>> aa = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int a = aaa->minPathSum(aa);
    std::cout << "Hello, World!\n";
    return 0;
}
