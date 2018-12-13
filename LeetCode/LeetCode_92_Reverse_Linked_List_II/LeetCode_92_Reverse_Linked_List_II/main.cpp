//
//  main.cpp
//  LeetCode_92_Reverse_Linked_List_II
//
//  Created by 舒毅文 on 2018/12/10.
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
    ListNode* reverseBetween(ListNode* c, int m, int n) {
        if (c == NULL || c->next == NULL || m == n) {
            return c;
        }
        vector<ListNode *> arr;
        int index = 1;
        ListNode *head = c;
        ListNode *left = NULL;
        ListNode *right = NULL;
        while (head != NULL) {
            if (index == m - 1) {
                left = head;
            } else if (index >= m && index <= n) {
                arr.push_back(head);
            } else if (index == n + 1) {
                right = head;
            } else if (index > n + 1) {
                break;
            }
            head = head->next;
            index++;
        }
        
        if (left != NULL) {
            for (int i = (int)arr.size() - 1; i >= 0; i--) {
                left->next = arr[i];
                left = left->next;
            }
            left->next = right;
        } else {
            c = arr.back();
            left = c;
            for (int i = (int)arr.size() - 2; i >= 0; i--) {
                left->next = arr[i];
                left = left->next;
            }
            left->next = right;
        }
        return c;
    }
};


/*
 一次遍历解决
 1.新建一个新的列表使用存储反转的分支
 */
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        ListNode *left = NULL;
        ListNode *reverseListHead;
        ListNode *reverseListFoot;
        ListNode *temp;
        ListNode *midTemp;
        ListNode *cHead = head;
        int index = 1;
        while (cHead != NULL) {
            if (index == m - 1) {
                left = cHead;
            } else if (index == m) {
                // 如果是等于m 说明这个点是反转之后的最后一个点
                reverseListFoot = new ListNode(cHead->val);
                reverseListHead = reverseListFoot;
            } else if (index > m && index <= n) {
                temp = new ListNode(cHead->val);
                midTemp = reverseListHead;
                reverseListHead = temp;
                temp->next = midTemp;
            }
            cHead = cHead->next;
            if (index == n) {
                break;
            }
            index++;
        }
        reverseListFoot->next = cHead;
        if (left == NULL) {
            return reverseListHead;
        } else {
            left->next = reverseListHead;
            return head;
        }
    }
};


class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        head = newhead;
        ListNode *p2 = head->next;
        ListNode *p1 = head;
        ListNode *q1;
        ListNode *q2 = head;
        int length = 0;
        while(q2) {
            if(++length < m) {
                p1 = p2;
                p2 = p2->next;
            }
            if(length == m) {
                q1 = p2;
            }
            if(length >=m && length < n) {
                q2 = q1->next;
                
                q1->next = q2->next;
                p1->next = q2;
                q2->next = p2;
                
                p2 = p1->next;
            }
            if(length >= n)
                break;
        }
        return head->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    
    Solution2 * aa = new Solution2();
    ListNode * res = aa->reverseBetween(node1, 2, 5);
    cout << "" << endl;
    return 0;
}
