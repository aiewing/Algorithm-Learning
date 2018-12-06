//
//  main.cpp
//  LeetCode_19_Remove_Nth_Node_From_End_of_List
//
//  Created by 舒毅文 on 2018/12/6.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建一个队列
        ListNode *res = head;
        queue<ListNode *> qu;
        int count = 0;
        while (head != NULL) {
            qu.push(head);
            count++;
            head = head->next;
            if (qu.size() > n + 1) {
                qu.pop();
                
            }
        }
        
        if (count == n) {
            return res->next;
        } else {
            qu.front()->next = qu.front()->next->next;
            return res;
        }
    }
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建一个队列
        ListNode *res = head;
        vector<ListNode *> arr;
        while (head != NULL) {
            arr.push_back(head);
            head = head->next;
        }
        
        if (arr.size() == n) {
            return res->next;
        } else {
            arr[arr.size() - n - 1]->next = arr[arr.size() - n - 1]->next->next;
            return res;
        }
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
    
    Solution1 *aa = new Solution1();
    ListNode * a = aa->removeNthFromEnd(node1, 2);
    cout << "" << endl;
    return 0;
}
