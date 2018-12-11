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
    
    Solution * aa = new Solution();
    ListNode * res = aa->reverseBetween(node1, 2, 4);
    cout << "" << endl;
    return 0;
}
