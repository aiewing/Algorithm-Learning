//
//  main.cpp
//  LeetCode_234_Palindrome_Linked_List
//
//  Created by 舒毅文 on 2018/12/18.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// 使用双指针法找到中点
// 在遍历的过程中反转前半部分的链表
// 在找到中点之后比较两部分的链表是否一致
// 时间复杂度O(n)
// 空间复杂度O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *headNode = new ListNode(0);
        headNode->next = head;
        // 已经反转的链表的头尾
        ListNode *headReNode = head;
        ListNode *footReNode = head;
        // 双指针
        ListNode *oneNode = head;
        ListNode *twoNode = head;
        
        int index = 0;
        while (twoNode != NULL) {
            // 需要反转
            // 说明链表的个数是单数
            if (twoNode->next == NULL) {
                oneNode = oneNode->next;
                break;
            }
            if (index++ > 0) {
                ListNode * temp = oneNode;
                footReNode->next = oneNode->next;
                oneNode = oneNode->next;
                
                headNode->next = temp;
                temp->next = headReNode;
                headReNode = temp;
            } else {
                oneNode = oneNode->next;
            }
            twoNode = twoNode->next->next;

        }
        // 判断是否是回文
        headNode = headNode->next;
        while (oneNode != NULL) {
            if (headNode->val != oneNode->val) {
                return false;
            }
            headNode = headNode->next;
            oneNode = oneNode->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(0);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(5);
    ListNode *node7 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
    
    Solution *aa = new Solution();
    bool a = aa->isPalindrome(node1);
    
    std::cout << "Hello, World!\n";
    return 0;
}
