//
//  main.cpp
//  LeetCode_23_Merge_k_Sorted_Lists
//
//  Created by 舒毅文 on 2018/12/10.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists.front();
        }
        ListNode *res = new ListNode(0);
        ListNode *cNode = res;
        bool flag = true;
        int minIndex = 0;
        while (flag) {
            flag = false;
            int minVal = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                ListNode * list = lists[i];
                if (list != NULL) {
                    flag = true;
                    if (list->val < minVal) {
                        minVal = list->val;
                        minIndex = i;
                    }
                }
            }
            if (flag) {
                cNode->next = lists[minIndex];
                cNode = cNode->next;
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        return res->next;
    }
};

class Solution1 {
public:
    struct cmp {
        bool operator () (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (auto list : lists) {
            if (list != NULL) {
                q.push(list);
            }
        }
        ListNode *res = new ListNode(0);
        ListNode *cNode = res;
        while (!q.empty()) {
            cNode->next = q.top();
            q.pop();
            cNode = cNode->next;
            if (cNode->next != NULL) {
                q.push(cNode->next);
            }
        }
        return res->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(4);
    ListNode * node3 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    
    ListNode * node4 = new ListNode(1);
    ListNode * node5 = new ListNode(3);
    ListNode * node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;
    
    ListNode * node7 = new ListNode(2);
    ListNode * node8 = new ListNode(6);
    node7->next = node8;
    
    vector<ListNode *> aaa = {node1, node4, node7};
    ListNode * node9 = new ListNode(2);
    ListNode * node10 = new ListNode(-1);
    
//    vector<ListNode *> aaa = {node9, NULL, node10};
    Solution1 *a = new Solution1();
    ListNode * aa = a->mergeKLists(aaa);
    
    std::cout << "Hello, World!\n";
    return 0;
}
