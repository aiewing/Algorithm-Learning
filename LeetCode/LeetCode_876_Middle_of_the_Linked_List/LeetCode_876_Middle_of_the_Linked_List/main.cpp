//
//  main.cpp
//  LeetCode_876_Middle_of_the_Linked_List
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> arr;
        while (head != NULL) {
            arr.push_back(head);
            head = head->next;
        }
        int mid = arr.size() / 2;
        cout << "" << endl;
        return arr[mid];
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3= new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    
    Solution *aa = new Solution();
    ListNode * a = aa->middleNode(node1);
    cout << "" << endl;
    return 0;
}
