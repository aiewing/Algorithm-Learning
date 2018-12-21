//
//  main.cpp
//  LeetCode_206_Reverse_Linked_List
//
//  Created by 舒毅文 on 2018/12/6.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
 int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        vector<ListNode*> res;
        while (head->next != NULL) {
            res.push_back(head);
            head = head->next;
        }
        ListNode * cHead = head;
        for (int i = res.size() - 1; i >= 0; i--) {
            cHead->next = res[i];
            cHead = cHead->next;
        }
        cHead->next = NULL;
        return head;
    }
};


// 递归法
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *aie = head;
        head = head->next;
        ListNode * res = reverseList(head);
        head->next = aie;
        aie->next = NULL;
        return res;
    }
};

// 链表逆转法
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = head;
        ListNode *temp = NULL;
        while (head != NULL) {
            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3= new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    Solution2 *aa = new Solution2();
    ListNode * a = aa->reverseList(node1);
    cout << "" << endl;
    return 0;
}
