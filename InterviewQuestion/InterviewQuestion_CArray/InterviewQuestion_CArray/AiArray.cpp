//
//  AiArray.cpp
//  InterviewQuestion_CArray
//
//  Created by 舒毅文 on 2019/3/19.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include "AiArray.hpp"

// 初始化
AiArray::AiArray() {
    _headNode = new NodeList(0);
    _tailNode = _headNode;
    _size = 0;
}

// 析构函数
AiArray::~AiArray() {
    _size = 0;
    delete _headNode;
}

// 增
bool AiArray::addData(TYPE data) {
    NodeList *newNode = new NodeList(data);
    newNode->next = NULL;
    
    _tailNode->next = newNode;
    newNode->prev = _tailNode;
    
    _tailNode = newNode;
    
    _size++;
    return true;
}

// 删
bool AiArray::deleteDataWithIndex(int index) {
    if (index < 0 || index >= _size) {
        return false;
    }
    int currentindex = 0;
    NodeList *tempNode = _headNode->next;
    while (tempNode != NULL) {
        if (index == currentindex) {
            // 删除节点
            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;
            _size--;
            return true;
        }
        tempNode = tempNode->next;
        currentindex++;
    }
    return false;
}

// 查
int AiArray::searchDataWithIndex(int index) {
    if (index < 0 || index >= _size) {
        return -1;
    }
    int currentindex = 0;
    NodeList *tempNode = _headNode->next;
    while (tempNode != NULL) {
        if (index == currentindex) {
            return tempNode->val;
        }
        tempNode = tempNode->next;
        currentindex++;
    }
    return -1;
}

// 改
bool AiArray::updataDataWithIndex(int index, TYPE data) {
    if (index < 0 || index >= _size) {
        return false;
    }
    int currentindex = 0;
    NodeList *tempNode = _headNode->next;
    while (tempNode != NULL) {
        if (index == currentindex) {
            // 修改节点
            tempNode->val = data;
            return true;
        }
        tempNode = tempNode->next;
        currentindex++;
    }
    return false;
}

// 插
bool AiArray::insertDataWithIndex(int index, TYPE data) {
    if (index < 0 || index >= _size) {
        return false;
    }
    if (index == _size - 1) {
        return addData(data);
    }
    
    int currentindex = 0;
    NodeList *tempNode = _headNode->next;
    while (tempNode != NULL) {
        if (index == currentindex) {
            // 插入节点
            NodeList *newNode = new NodeList(data);
            NodeList *nextNode = tempNode->next;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            
            tempNode->next = newNode;
            newNode->prev = tempNode;
            
            _size++;
            return true;
        }
        tempNode = tempNode->next;
        currentindex++;
    }
    return false;
}
