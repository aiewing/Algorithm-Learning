//
//  main.cpp
//  AliInterviewQuestion_Max_Difference_Of_Binary_Tree_Node
//
//  Created by Aiewing on 2018/11/11.
//  Copyright © 2018 Aiewing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sys/time.h>

using namespace std;

/*
 你用一个函数，输入一个二叉树的时候，当树中每一个节点存放一个整数值，怎么使得函数返回二叉树中相差最大的两个节点间的差值绝对值
 */

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int v):value(v), left(NULL), right(NULL) {}
};

static int maxNum = INT_MIN;
static int minNum = INT_MAX;

// 计算最大最小
void calculateNum(Node *node) {
    if (node->value > maxNum) {
        maxNum = node->value;
    }
    if (node->value < minNum) {
        minNum = node->value;
    }
}

// 1.递归遍历 寻找最大最小的节点
// 例子中字符串1000000次测试，平均时间：36-39毫秒
// 时间复杂度为O(log2N)
// 空间复杂度为O(log2N)
// 优点：简单易懂，使用的额外空间少，是常用的二叉树遍历之一，这种算法叫前序遍历，还有类似的中序遍历，后序遍历。
// 缺点：使用递归，理论上效率不是最高的算法
int maxDifference1(Node *node) {
    calculateNum(node);
    if (node->left != NULL) {
        maxDifference1(node->left);
    }
    if (node->right != NULL) {
        maxDifference1(node->right);
    }
    return maxNum - minNum;
}

// 2.非递归遍历 寻找最大最小的节点
// 例子中字符串100000次测试，平均时间：1200毫秒左右
// 时间复杂度为O(N^2)
// 空间复杂度为O(N^2)
// 优点：使用了非递归的方式，比递归的方式比较容易理解
// 缺点：由于使用了c++数组去存二叉树的节点，所以算法的运行时间较长，使用的额外内存较多，当二叉树节点比较多的时候，数据就会存储很多的节点，造成了不必要的内存消耗。
int maxDifference2(Node *node) {
    Node *temp;
    vector<Node *> arr;
    int front = 0;
    int rear = 1;
    arr.push_back(node);
    while (front != rear) {
        temp = arr[front++];
        calculateNum(temp);
        if (temp->left != NULL) {
            arr.push_back(temp->left);
            rear++;
        }
        if (temp->right != NULL) {
            arr.push_back(temp->right);
            rear++;
        }
    }
    return maxNum - minNum;
}

// 3.回溯遍历 寻找最大最小的节点
// 例子中字符串100000次测试，平均时间：880毫秒
// 时间复杂度为O(N^2)
// 空间复杂度为O(log2N)
// 优点：使用了回溯的方式，相比上面的l解法，额外内存消耗变低了很多，但是实际算的算法的运算时间没有减少。
// 缺点：出栈入栈时间消耗比较大，算法本身效率也不高。
int maxDifference3(Node *node) {
    stack<Node *> st;
    while (node != NULL || !st.empty()) {
        while (node != NULL) {
            calculateNum(node);
            st.push(node);
            node = node->left;
        }
        if (!st.empty()) {
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return maxNum - minNum;
}

int64_t getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
    
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    
    long startTime = getCurrentTime();
    for (int i = 0; i < 1000000; i++) {
        int diff = maxDifference3(node1);
    }
    long endTime = getCurrentTime();
    long time = endTime - startTime;
    cout << time << endl;
    
    
    return 0;
}
