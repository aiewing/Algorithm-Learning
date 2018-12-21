//
//  main.cpp
//  LeetCode_107_Binary_Tree_Level_Order_Traversal_II
//
//  Created by 舒毅文 on 2018/12/17.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 递归
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        aiewing(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void aiewing(TreeNode *root, int level) {
        if (root == NULL) {
            return;
        }
        // 加入数据
        if (res.size() <= level) {
            vector<int> arr;
            res.push_back(arr);
        }
        res[level].push_back(root->val);
        if (root->left != NULL) {
            aiewing(root->left, level + 1);
        }
        if (root->right != NULL) {
            aiewing(root->right, level + 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution *aa = new Solution();
    vector<vector<int>> res = aa->levelOrderBottom(node1);
    
    return 0;
}