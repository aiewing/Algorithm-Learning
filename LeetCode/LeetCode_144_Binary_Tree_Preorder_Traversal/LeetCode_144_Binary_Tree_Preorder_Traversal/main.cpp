//
//  main.cpp
//  LeetCode_144_Binary_Tree_Preorder_Traversal
//
//  Created by 舒毅文 on 2018/12/21.
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
    vector<int> preorderTraversal(TreeNode* root) {
        aiewing(root);
        return res;
    }
    
    void aiewing(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        res.push_back(root->val);
        if (root->left != NULL) {
            aiewing(root->left);
        }
        if (root->right != NULL) {
            aiewing(root->right);
        }
    }
};

// 非递归 模拟出栈入栈
class Solution1 {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        aiewing(root);
        return res;
    }
    
    void aiewing(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        res.push_back(root->val);
        if (root->left != NULL) {
            aiewing(root->left);
        }
        if (root->right != NULL) {
            aiewing(root->right);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
