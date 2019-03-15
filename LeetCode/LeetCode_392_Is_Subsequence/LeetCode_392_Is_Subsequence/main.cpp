//
//  main.cpp
//  LeetCode_392_Is_Subsequence
//
//  Created by 舒毅文 on 2019/3/15.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
 从子序列的第一个字符开始，遍历父字符串，查找是否存在这个字符串
    如果存在，那就开始查找子序列的下一个字符串
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        if (m == 0) {
            return true;
        }
        int n = t.size();
        int index = 0;
        for (int i = 0; i < m; i++) {
            while (index < n) {
                char a = s[i];
                char b = t[index++];
                if (a == b) {
                    if (i == m - 1) {
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
