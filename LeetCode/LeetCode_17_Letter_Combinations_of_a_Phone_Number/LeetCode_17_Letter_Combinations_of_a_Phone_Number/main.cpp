//
//  main.cpp
//  LeetCode_17_Letter_Combinations_of_a_Phone_Number
//
//  Created by 舒毅文 on 2019/3/25.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        int n = (int)digits.size();
        if (n == 0) {
            return res;
        }
        aiewing("", digits, 0, n);
        return res;
    }
    
    void aiewing(string str, string digits, int index, int n) {
        if (index == n) {
            res.push_back(str);
            return;
        } else {
            int start = 0;
            if (digits[index] == '8' || digits[index] == '9') {
                start = 1;
            }
            int num = digits[index] - '0' - 2;
            string temp = str;
            temp.push_back(num * 3 + 'a' + start);
            aiewing(temp, digits, index + 1, n);
            temp = str;
            temp.push_back(num * 3 + 'a' + 1 + start);
            aiewing(temp, digits, index + 1, n);
            temp = str;
            temp.push_back(num * 3 + 'a' + 2 + start);
            aiewing(temp, digits, index + 1, n);
            
            if (digits[index] == '9' || digits[index] == '7') {
                temp = str;
                temp.push_back((num * 3 + 3 + start) + 'a');
                aiewing(temp, digits, index + 1, n);
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    vector<string> bbb = aaa->letterCombinations("7");
    std::cout << "Hello, World!\n";
    return 0;
}
