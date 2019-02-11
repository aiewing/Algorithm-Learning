//
//  main.cpp
//  LeetCode_83_Remove_Duplicates_from_Sorted_List
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
        ListNode *fitstNode = head;
        ListNode *tempNode = head;
        head = head->next;
        while (head != NULL) {
            if (tempNode->val != head->val) {
                tempNode->next = head;
                tempNode = tempNode->next;
            }
            head = head->next;
        }
        tempNode->next = NULL;
        return fitstNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
