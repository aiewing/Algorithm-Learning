//
//  main.cpp
//  LeetCode_961_N_Repeated_Element_in_Size_2N_Array
//
//  Created by 舒毅文 on 2019/3/21.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> aie(10001, 0);
        for (int i = 0; i < A.size(); i++) {
            if (aie[A[i]] > 0) {
                return A[i];
            } else {
                aie[A[i]]++;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
