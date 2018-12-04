//
//  main.cpp
//  LeetCode_15_3Sum
//
//  Created by 舒毅文 on 2018/12/4.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        unordered_set<int> tempSet;
        for (int i = 0; i < nums.size(); i++) {
            tempSet.insert(nums[i]);
        }
        int count = (int)nums.size();
        for (int i = 0; i < count - 2; i++) {
            for (int j = i + 1; j < count - 1; j++) {
                if ((nums[i] + nums[j]) > 0) {
                    break;
                }
                // 去重复
                if (res.size() > 0) {
                    if (res.back()[0] == nums[i] && res.back()[1] == nums[j]) {
                        continue;
                    }
                }
                if (tempSet.count(-nums[i] - nums[j])) {
                    vector<int> aie;
                    aie.push_back(nums[i]);
                    aie.push_back(nums[j]);
                    aie.push_back(-nums[i] - nums[j]);
                    res.push_back(aie);
                    break;
                }
            }
        }
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        unordered_set<int> sss;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            //去重1
            if(i != 0 && nums[i - 1] == nums[i])
                continue;
            
            sss.clear();
            for(int j = i + 1; j < nums.size(); j++) {
                if(sss.count(-nums[i] - nums[j])) {
                    ans.push_back({nums[i],nums[j],-nums[i] - nums[j]});
                    //去重2
                    while(nums[j + 1] == nums[j] && j + 1 < nums.size())
                        j++;
                }
                sss.insert(nums[j]);
            }
            
        }
        
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution *a = new Solution();
    vector<int> aa = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = a->threeSum(aa);
    cout << "" ;
    return 0;
}
