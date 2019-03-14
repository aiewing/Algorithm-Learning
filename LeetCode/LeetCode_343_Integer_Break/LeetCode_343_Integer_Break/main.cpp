//
//  main.cpp
//  LeetCode_343_Integer_Break
//
//  Created by 舒毅文 on 2019/3/14.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res;
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        int a = 1;
        aie(n);
        for (int i = 0; i < res.size(); i++) {
            a *= res[i];
        }
        return a;
    }
    
    void aie(int n) {
        if (n > 4) {
            if (n % 2 == 0) {
                aie(n / 2);
                aie(n / 2);
            } else {
                aie(n / 2);
                aie(n / 2 + 1);
            }
        } else {
            res.push_back(n);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
