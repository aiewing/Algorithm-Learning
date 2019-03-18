//
//  main.cpp
//  LeetCode_118_Pascal's_Triangle
//
//  Created by Aiewing on 2019/3/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> arr = res[i - 1];
            for (int j = 0; j < arr.size() - 1; j++) {
                res[i].push_back(arr[j] + arr[j + 1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
