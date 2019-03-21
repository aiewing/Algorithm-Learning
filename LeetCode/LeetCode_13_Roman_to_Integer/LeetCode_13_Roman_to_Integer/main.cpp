//
//  main.cpp
//  LeetCode_13_Roman_to_Integer
//
//  Created by 舒毅文 on 2019/3/21.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.size() == 1) {
            return aiewing(s[0]);
        }
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int a = aiewing(s[i]);
            int b = aiewing(s[i + 1]);
            if (a >= b) {
                res += a;
            } else {
                res -= a;
            }
        }
        res += aiewing(s.back());
        return res;
    }
    
    int aiewing(char c) {
        if (c == 'I') {
            return 1;
        } else if (c == 'V') {
            return 5;
        } else if (c == 'X') {
            return 10;
        } else if (c == 'L') {
            return 50;
        } else if (c == 'C') {
            return 100;
        } else if (c == 'D') {
            return 500;
        } else if (c == 'M') {
            return 1000;
        }
        return 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aaa = new Solution();
    int aa = aaa->romanToInt("MCMXCIV");
    cout << "";
    return 0;
}
