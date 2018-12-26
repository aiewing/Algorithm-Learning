//
//  main.cpp
//  LeetCode_Binary_Tree_Postorder_Traversal
//
//  Created by 舒毅文 on 2018/12/26.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> res;
    stack<TreeNode *> sta;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        aiewing(root);
        return res;
    }
    
    void aiewing(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        if (root->left != NULL) {
            aiewing(root->left);
        }
        if (root->right != NULL) {
            aiewing(root->right);
        }
        res.push_back(root->val);
    }
};

class Solution2 {
public:
    vector<int> res;
    stack<TreeNode *> sta;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        // 上次访问的节点
        TreeNode *lastNode = NULL;
        // 先把节点移动到最左下
        while (root != NULL) {
            sta.push(root);
            root = root->left;
        }
        while (!sta.empty()) {
            root = sta.top();
            sta.pop();
            if (root->right == NULL || root->right == lastNode) {
                res.push_back(root->val);
                lastNode = root;
            } else {
                sta.push(root);
                root = root->right;
                while (root != NULL) {
                    sta.push(root);
                    root = root->left;
                }
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
