//
//  main.cpp
//  LeetCode_24_Swap_Nodes_in_Pairs
//
//  Created by 舒毅文 on 2018/12/26.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = new ListNode(0);
        ListNode *newNode = newHead;
        ListNode *lastNode = NULL;
        while (head != NULL) {
            if (lastNode == NULL) {
                lastNode = head;
                head = head->next;
            } else {
                // 都加到新的链表后面
                newNode->next = head;
                head = head->next;
                newNode = newNode->next;
                newNode->next = lastNode;
                newNode = newNode->next;
                lastNode = NULL;
            }
        }
        newNode->next = lastNode;
        return newHead->next;
    }
};

// 递归法 交换两个节点
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 交换两个节点
        ListNode *one = head->next;
        head->next = one->next;
        one->next = head;
        ListNode *reNode = swapPairs(head->next);
        head->next = reNode;
        return one;
    }
};

class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 交换两个节点
        ListNode *one = head->next;
        head->next = swapPairs(head->next->next);
        one->next = head;
        return one;
    
};


int main(int argc, const char * argv[]) {
    
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution1 *a = new Solution1();
    ListNode *aa = a->swapPairs(node4);
    cout << "" << endl;
    return 0;
}
