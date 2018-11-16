//
//  main.cpp
//  LeetCode_102_Binary_Tree_Level_Order_Traversal
//
//  Created by 舒毅文 on 2018/11/16.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root != NULL) {
            aiewing(root, 0);
        }
        return res;
    }
    
    void aiewing(TreeNode *node, int level) {
        if (res.size() <= level) {
            // 创建一个
            vector<int> subVe;
            res.push_back(subVe);
        }
        res[level].push_back(node->val);
        if (node->left != NULL) {
            aiewing(node->left, level + 1);
        }
        if (node->right != NULL) {
            aiewing(node->right, level + 1);
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

    
    Solution *so = new Solution();
    vector<vector<int>> res = so->levelOrder(node1);
    
    return 0;
}
