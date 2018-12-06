//
//  main.cpp
//  LeetCode_21_Merge_Two_Sorted_Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        while (l1 != NULL || l2 != NULL) {
            if (l2 == NULL || (l1 != NULL && l1->val <= l2->val)) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        return res->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
