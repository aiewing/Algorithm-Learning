//
//  main.cpp
//  LeetCode_164_Maximum_Gap
//
//  Created by 舒毅文 on 2018/12/5.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maxGap = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            maxGap = max(nums[i + 1] - nums[i], maxGap);
        }
        return maxGap;
    }
};

// 桶排序
class Solution1 {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        // 先找出最大和最小值
        int minNum = nums.front();
        int maxNum = nums.front();
        for (int i = 0; i < nums.size(); i++) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        
        // 先确定桶大小
        int bucketSize = max(1, (maxNum - minNum) / ((int)nums.size() - 1));
        int bucketCount = ceil((maxNum - minNum + 1) / (float)bucketSize);
        vector<vector<int>> bucket(bucketCount);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxNum) {
                bucket.back().push_back(nums[i]);
                continue;
            }
            // 看数据是在n哪个桶中的
            int bucketIndex = (nums[i] - minNum) / bucketSize;
            bucket[bucketIndex].push_back(nums[i]);
        }
    
        nums.resize(0);
        for (int i = 0; i < bucket.size(); i++) {
            // 计算大小
            if (!bucket[i].empty()) {
                sort(bucket[i].begin(), bucket[i].end());
                nums.insert(nums.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        int maxGap = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            maxGap = max(nums[i + 1] - nums[i], maxGap);
        }
        return maxGap;
    }
};

class Solution3 {
public:
    //bool used = false;
    
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for(auto subnum : nums) {
            minval = min(subnum, minval);
            maxval = max(subnum, maxval);
        }
        
        int bucketSize = max(1, (maxval - minval) / ((int)nums.size() - 1));
        int bucketNum = (maxval - minval) / bucketSize;
        
        vector<int> bucketsMin(bucketNum, INT_MAX);
        vector<int> bucketsMax(bucketNum, INT_MIN);
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxval || nums[i] == minval) {
                continue;
            }
            int index = (nums[i] - minval) / bucketSize;
            bucketsMin[index] = min(bucketsMin[index], nums[i]);
            bucketsMax[index] = max(bucketsMax[index], nums[i]);
        }
        int maxGap = 0;
        int pre = minval;
        for(int i = 0; i < bucketNum; i++) {
            if(bucketsMin[i] == INT_MAX || bucketsMax[i] == INT_MIN) {
                continue;
            }
            maxGap = max(maxGap, bucketsMin[i] - pre);
            pre = bucketsMax[i];
        }
        maxGap = max(maxGap, maxval - pre);
        return maxGap;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> a;
    for (int i = 0; i < 10000; i++) {
        int q = random() % 100000;
        a.push_back(q);
    }
//    vector<int> a = { 21, 35, 49, 77, 83,1, 35, 49, 99, 86};
    Solution3 * aa = new Solution3();
    int res = aa->maximumGap(a);
    
    cout << res << endl;
    return 0;
}
