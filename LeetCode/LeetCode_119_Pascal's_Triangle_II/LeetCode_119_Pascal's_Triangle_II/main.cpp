//
//  main.cpp
//  LeetCode_119_Pascal's_Triangle_II
//
//  Created by Aiewing on 2019/3/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *aaa = new Solution();
    aaa->getRow(5);
    std::cout << "Hello, World!\n";
    return 0;
}
