//
//  main.cpp
//  LeetCode_25_Reverse_Nodes_in_k_Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution *a = new Solution();
    ListNode *aa = a->reverseKGroup(node1, 2);
    cout << "" << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
