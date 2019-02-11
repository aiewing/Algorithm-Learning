//
//  main.cpp
//  LeetCode_82_Remove_Duplicates_from_Sorted_List_II
//
//  Created by 舒毅文 on 2019/2/11.
//  Copyright © 2019 舒毅文. All rights reserved.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *fitstNode = new ListNode(0);
        fitstNode->next = head;
        ListNode *tempNode = head;
        ListNode *headNode = fitstNode;
        head = head->next;
        int index = 1;
        while (head != NULL) {
            if (tempNode->val == head->val) {
                index++;
            } else {
                if (index == 1) {
                    headNode->next = tempNode;
                    headNode = headNode->next;
                }
                tempNode = head;
                index = 1;
            }
            head = head->next;
        }
        if (index > 1) {
            headNode->next = NULL;
        } else {
            headNode->next = tempNode;
        }
        return fitstNode->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(4);
    ListNode * node6 = new ListNode(4);
    ListNode * node7 = new ListNode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    
    ListNode * node11 = new ListNode(1);
    ListNode * node12 = new ListNode(1);
    node11->next = node12;
    
    Solution * aa = new Solution();
    aa->deleteDuplicates(node11);
    
    
    return 0;
}
