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
        // 先定义两串链表
        ListNode *leftHeadNode = new ListNode(0);
        ListNode *rightHeadNode = new ListNode(0);
        ListNode *leftCurrentNode = leftHeadNode;
        ListNode *rightCurrentNode = rightHeadNode;
        while (head != NULL) {
            // 判断当前的值
            if (head->val < x) {
                leftCurrentNode->next = head;
                leftCurrentNode = leftCurrentNode->next;
            } else {
                rightCurrentNode->next = head;
                rightCurrentNode = rightCurrentNode->next;
            }
            head = head->next;
        }
        leftCurrentNode->next = rightHeadNode->next;
        rightCurrentNode->next = NULL;
        return leftHeadNode->next;
    }
};

class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHeadNode = new ListNode(0);
        ListNode *rightHeadNode = new ListNode(0);
        ListNode *leftCurrentNode = leftHeadNode;
        ListNode *rightCurrentNode = head;
        while (rightCurrentNode != NULL) {
            // 判断当前的值
            if (rightCurrentNode->val < x) {
                leftCurrentNode->next = rightCurrentNode;
                leftCurrentNode = leftCurrentNode->next;
                rightCurrentNode = rightCurrentNode->next;
                leftCurrentNode->next = NULL;
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
    Solution1 *a = new Solution1();
    ListNode * res = a->partition(node1, 3);
    
    cout << "" ;
    return 0;
}
