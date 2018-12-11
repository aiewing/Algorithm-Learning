//
//  main.cpp
//  LeetCode_94_Binary_Tree_Inorder_Traversal
//
//  Created by 舒毅文 on 2018/12/11.
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

// 递归
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        aiewing(root);
        return res;
    }
    
    void aiewing(TreeNode *root) {
        if (root == NULL) {
            return ;
        }
        if (root->left != NULL) {
            aiewing(root->left);
        }
        res.push_back(root->val);
        if (root->right != NULL) {
            aiewing(root->right);
        }
    }
};

// 非递归
class Solution1 {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                res.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return res;
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
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    
    Solution1 *aa = new Solution1();
    aa->inorderTraversal(node1);
    
    return 0;
}
