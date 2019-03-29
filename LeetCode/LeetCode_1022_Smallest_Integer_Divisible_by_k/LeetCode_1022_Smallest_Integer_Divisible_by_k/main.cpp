//
//  main.cpp
//  LeetCode_1022_Smallest_Integer_Divisible_by_k
//
//  Created by 舒毅文 on 2019/3/27.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int res;
    int smallestRepunitDivByK(int K) {
        int n = K % 10;
        if (n == 1 || n == 3 || n == 7 || n == 9 ) {
            aiewing(K, 0, 0);
            return res;
        }
        return -1;
    }
    
    void aiewing(int K, int index, int add) {
        if ((int)pow(10, index) > K) {
            if (add > 0) {
                res++;
            }
            if (K % 10 != 1) {
                res++;
            }
            return;
        }
        int n = (K / (int)pow(10, index)) % 10;
        // 让现在的这个数变成1
        for (int i = 0; i < 10; i++) {
            int sub = add + i * n;
            if (sub % 10 == 1) {
                add = (sub / 10) % 10;
                res++;
                aiewing(K, index + 1, add);
                return;
            }
        }
        res = -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution * aaa = new Solution();
    int bbb = aaa->smallestRepunitDivByK(7);
    std::cout << "Hello, World!\n";
    return 0;
}
