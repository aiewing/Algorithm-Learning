//
//  main.cpp
//  LeetCode_22_Generate_Parentheses
//
//  Created by Aiewing on 2019/3/24.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 限制条件：
 - 第一个位置肯定是左括号
 - 通过递归
 */
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        aiewing("(", 1, 0, n);
        return res;
    }
    
    void aiewing(string str, int left, int right, int n) {
        // 输出
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }
        
        // 只能左边
        if (left == right && left < n) {
            aiewing(str + "(", left + 1, right, n);
            return;
        }
        
        // 只能右边
        if (left > right && left == n) {
            aiewing(str + ")", left, right + 1, n);
            return;
        }
        
        // 左右都可以
        if (left > right && left < n) {
            aiewing(str + "(", left + 1, right, n);
            aiewing(str + ")", left, right + 1, n);
            return;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<string> bbb = aaa->generateParenthesis(3);
    std::cout << "Hello, World!\n";
    return 0;
}
