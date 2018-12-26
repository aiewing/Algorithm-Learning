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
        stack<TreeNode *> sta;
        while (root != NULL || !sta.empty()) {
            while (root != NULL) {
                res.push_back(root->val);
                sta.push(root);
                root = root->left;
            }
            if (!sta.empty()) {
                root = sta.top();
                sta.pop();
                root = root->right;
            }
        }
        return res;
    }
};

// 非递归 模拟出栈入栈
class Solution2 {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        stack<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty()) {
            res.push_back(root->val);
            if (root->right) {
                sta.push(root->right);
            }
            if (root->left) {
                root = root->left;
            } else {
                root = sta.top();
                sta.pop();
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
