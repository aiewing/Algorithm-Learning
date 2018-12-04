//
//  main.cpp
//  LeetCode_86_Partition_List
//
//  Created by 舒毅文 on 2018/12/3.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 左边链表头
        ListNode *leftHeadNode = new ListNode(0);
        // 右边链表头
        ListNode *rightHeadNode = new ListNode(0);
        // 左边链表的当前位置
        ListNode *leftCurrentNode = leftHeadNode;
        // 右边链表的当前位置
        ListNode *rightCurrentNode = rightHeadNode;
        while (head != NULL) {
            if (head->val < x) {
                // 把小于x的节点放到左链表最后 并移动当前节点到下个节点
                leftCurrentNode->next = head;
                leftCurrentNode = leftCurrentNode->next;
            } else {
                // 把大于等于x的节点放到右链表最后 并移动当前节点到下个节点
                rightCurrentNode->next = head;
                rightCurrentNode = rightCurrentNode->next;
            }
            head = head->next;
        }
        // 拼接两个列表
        leftCurrentNode->next = rightHeadNode->next;
        rightCurrentNode->next = NULL;
        return leftHeadNode->next;
    }
};

class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        // 左边链表头
        ListNode *leftHeadNode = new ListNode(0);
        // 原节点的父节点
        ListNode *fatherHeadNode = new ListNode(0);
        // 为了让第一个节点拥有父节点 删除节点的时候容易一点 所以为原链表设置一个父节点
        fatherHeadNode->next = head;
        // 左边链表的当前位置
        ListNode *leftCurrentNode = leftHeadNode;
        // 原链表的当前位置
        ListNode *headCurrentNode = fatherHeadNode;
        while (headCurrentNode->next != NULL) {
            // 判断当前的值
            if (headCurrentNode->next->val < x) {
                // 把小于x的节点放到左链表最后 并移动当前节点到下个节点
                leftCurrentNode->next = headCurrentNode->next;
                leftCurrentNode = leftCurrentNode->next;
                // 删除当前的节点
                headCurrentNode->next = headCurrentNode->next->next;
                leftCurrentNode->next = NULL;
            } else {
                // 当前节点不变 移动当前节点到下个节点
                headCurrentNode = headCurrentNode->next;
            }
        }
        // 拼接两个列表
        leftCurrentNode->next = fatherHeadNode->next;
        return leftHeadNode->next;
    }
};

class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        // 当遇到第一个小于x的就设置成左半部分的头
        // 当遇到第一个大于等于x的就设置成右半部分的头
        // 左边链表头
        ListNode *leftHeadNode = new ListNode(0);
        // 右边链表头
        ListNode *rightHeadNode = new ListNode(0);
        rightHeadNode->next = head;
        // 左边链表的当前位置
        ListNode *leftCurrentNode = leftHeadNode;
        // 右边链表的当前位置
        ListNode *rightCurrentNode = rightHeadNode;
        while (rightCurrentNode->next != NULL) {
            if (rightCurrentNode->next->val < x) {
                // 移除这个点 并重新拼接原来的节点
                leftCurrentNode->next = rightCurrentNode->next;
                leftCurrentNode = leftCurrentNode->next;
                rightCurrentNode->next = rightCurrentNode->next->next;
            } else {
                rightCurrentNode = rightCurrentNode->next;
            }
        }
        leftCurrentNode->next = rightHeadNode->next;
        return leftHeadNode->next;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    Solution2 *a = new Solution2();
    ListNode * res = a->partition(node1, 3);
    
    cout << "" ;
    return 0;
}
