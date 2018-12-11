//
//  main.cpp
//  LeetCode_215_Kth_Largest_Element_in_an_Array
//
//  Created by 舒毅文 on 2018/12/11.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 先建堆 把K个数字放在大顶堆中
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> subArr(nums.begin(), nums.begin() + k);
        for (int i = subArr.size() / 2 - 1; i >= 0; i--) {
            adjustHeap(subArr, i, k);
        }
        cout << "" << endl;
        return 1;
    }
    
    // 堆化
    void adjustHeap(vector<int> &arr, int i, int k) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int top = i;
        if (left < k && arr[left] > arr[top]) {
            top = left;
        }
        if (right < k && arr[right] > arr[top]) {
            top = right;
        }
        if (top != i) {
            int temp = arr[i];
            arr[i] = arr[top];
            arr[top] = temp;
            adjustHeap(arr, top, k);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {3, 5, 2, 5, 7, 8, 2, 4 , 4, 5, 2};
    Solution *aa = new Solution();
    int res = aa->findKthLargest(arr, 5);
    return 0;
}
