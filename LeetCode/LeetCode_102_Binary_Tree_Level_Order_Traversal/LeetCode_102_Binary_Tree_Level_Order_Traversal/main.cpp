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

// 解法一：前序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
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

// 解法二：非递归遍历
// 根据的上一层的数据，可以得到下一层的数据
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution2 {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 先新建一个数组
        vector<vector<int>> res;
        vector<vector<TreeNode *>> treeArr;
        if (root != NULL) {
            vector<int> first;
            first.push_back(root->val);
            res.push_back(first);
            
            vector<TreeNode *> firstTree;
            firstTree.push_back(root);
            treeArr.push_back(firstTree);
            
            int i = 0;
            while (treeArr.size() > i) {
                vector<TreeNode *> temp = treeArr[i];
                
                vector<int> last;
                vector<TreeNode *> lastTree;
                
                for (int j = 0; j < temp.size(); j++) {
                    TreeNode *tempTree = temp[j];
                    if (tempTree->left != NULL) {
                        last.push_back(tempTree->left->val);
                        lastTree.push_back(tempTree->left);
                    }
                    if (tempTree->right != NULL) {
                        last.push_back(tempTree->right->val);
                        lastTree.push_back(tempTree->right);
                    }
                }
                if (last.size() > 0) {
                    res.push_back(last);
                    treeArr.push_back(lastTree);
                }
                i++;
            }
        }
        return res;
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

    
    Solution2 *so = new Solution2();
    vector<vector<int>> res = so->levelOrder(node1);
    
    return 0;
}
