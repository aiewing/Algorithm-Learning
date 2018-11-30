//
//  main.cpp
//  LeetCode_74_Search_a_2D_Matrix
//
//  Created by 舒毅文 on 2018/11/30.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        // 先判断target在什么范围里面
        vector<int> resArr;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> arr = matrix[i];
            if (arr.size() == 0) {
                break;
            }
            if (target >= arr.front() && target <= arr.back()) {
                if (target == arr.front() || target == arr.back()) {
                    return true;
                } else {
                    resArr = arr;
                    break;
                }
                
            }
            if (i > 0) {
                if (arr.back() > target && arr.front() < target) {
                    return false;
                }
            }
        }
        
        // 使用二分法查找
        int left = 0;
        int right = resArr.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == resArr[left] || target == resArr[right]) {
                return true;
            }
            if (target < resArr[mid]) {
                // 左边
                right = mid - 1;
            } else if (target > resArr[mid]) {
                // 右边
                left = mid + 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution * aa = new Solution();
//    vector<vector<int>> matrix = {{1}};
    vector<vector<int>> matrix = {{-8,-7,-5,-3,-3,-1,1},{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    bool a = aa->searchMatrix(matrix, -5);
    //[[-8,-7,-5,-3,-3,-1,1],[2,2,2,3,3,5,7],[8,9,11,11,13,15,17],[18,18,18,20,20,20,21],[23,24,26,26,26,27,27],[28,29,29,30,32,32,34]]
    cout << "";
    return 0;
}
