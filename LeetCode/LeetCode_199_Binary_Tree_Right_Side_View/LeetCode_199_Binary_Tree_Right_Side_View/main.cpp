//
//  main.cpp
//  LeetCode_199_Binary_Tree_Right_Side_View
//
//  Created by 舒毅文 on 2018/12/26.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 回溯
/*
 1.一直遍历右边的 如果没有右边的节点 那就取左边的 如果没有左边的
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> sta;
        if (root == NULL) {
            return res;
        }
        int index = 0;
        while (1) {
            if (sta.size() >= index) {
                res.push_back(root->val);
                index++;
                sta.push(root);
            } else {
                sta.push(root);
            }
            if (root->right != NULL) {
                root = root->right;
            } else {
                if (root->left != NULL) {
                    root = root->left;
                } else {
                    // 如果左右都没有 那就回溯
                    while (sta.top()->left == NULL) {
                        sta.pop();
                    }
                    root = sta.top()->left;
                }
            }
            std::cout << "Hello, World!\n";
        }
    }
};

// 递归
class Solution1 {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        aiewing(root, 1);
        return res;
    }
    void aiewing(TreeNode *root, int k) {
        if (root != NULL) {
            if (k > res.size()) {
                res.push_back(root->val);
            }
        } else {
            return;
        }
        if (root->right != NULL) {
            aiewing(root->right, k + 1);
        }
        if (root->left != NULL) {
            aiewing(root->left, k + 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = node8;
    
    Solution1 *a = new Solution1();
    vector<int> aa = a->rightSideView(node1);
    
    std::cout << "Hello, World!\n";
    return 0;
}
