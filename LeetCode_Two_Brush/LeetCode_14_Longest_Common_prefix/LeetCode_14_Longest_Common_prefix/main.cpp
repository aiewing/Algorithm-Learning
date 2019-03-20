//
//  main.cpp
//  LeetCode_14_Longest_Common_prefix
//
//  Created by Aiewing on 2019/3/20.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 暴力求解法
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n < 1) {
            return "";
        } else if (n == 1) {
            return strs[0];
        }
        int index = 0;
        while (1) {
            string subStr = strs[0];
            char c;
            if (index < subStr.size()) {
                c = subStr[index];
            } else {
                break;
            }
            for (int i = 1; i < strs.size(); i++) {
                string sub = strs[i];
                if (index >= sub.size() || sub[index] != c) {
                    return sub.substr(0, index);
                }
            }
            index++;
        }
        return strs[0].substr(0, index);
    }
};


int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<string> bbb = {"c","c"};
    string aa = aaa->longestCommonPrefix(bbb);
    cout << "" ;
    return 0;
}
