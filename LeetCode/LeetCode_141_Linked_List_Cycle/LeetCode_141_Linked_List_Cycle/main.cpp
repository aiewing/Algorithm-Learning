//
//  main.cpp
//  LeetCode_141_Linked_List_Cycle
//
//  Created by 舒毅文 on 2018/12/6.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        set<ListNode *> resSet;
        while (head != NULL) {
            if (resSet.find(head) != resSet.end()) {
                return true;
            }
            resSet.insert(head);
            head = head->next;
        }
        return false;
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
    node5->next = node1;
    
    Solution *aa = new Solution();
    bool a = aa->hasCycle(node1);
    cout << "" << endl;
    return 0;
}
