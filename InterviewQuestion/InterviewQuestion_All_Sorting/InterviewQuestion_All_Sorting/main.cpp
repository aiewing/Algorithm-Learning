//
//  main.cpp
//  InterviewQuestion_All_Sorting
//
//  Created by 舒毅文 on 2018/11/20.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 题目
    列举所有的排序并分析
 */


/// 冒泡排序
vector<int> sorting1(vector<int> arr) {
    // 记录是否交换
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                // 交换
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                flag = true;
            }
        }
    }
    return arr;
}

/// 选择排序
vector<int> sorting2(vector<int> arr) {
    int minIndex;
    for (int i = 0; i < arr.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            // 先找出一个最小的数
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        // 和i - 1位交换
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    
    return arr;
}

/// 插入排序
vector<int> sorting3(vector<int> arr) {
    // 已经排好序的位置
    int sortedIndex = 0;
    int current;
    for (int i = 1; i < arr.size(); i++) {
        current = arr[i];
        for (int j = sortedIndex; j >= 0; j--) {
            
            if (current > arr[j]) {
                arr[j + 1] = current;
                sortedIndex++;
                break;
            } else if (current < arr[j]) {
                arr[j + 1] = arr[j];
                if (j == 0) {
                    arr[0] = current;
                    sortedIndex++;
                    break;
                }
            }
        }
    }
    
    return arr;
}

/// 希尔排序
vector<int> sorting4(vector<int> arr) {
    int gap = arr.size() / 2;
    while(gap >= 1) {
        // 把距离为gap的元素编为一组 扫描所有组
        for (int i = gap; i < arr.size(); i++) {
            int j = 0;
            int temp = arr[i];
            
            // 对距离为gap的元素组进行排序
            for (j = i - gap; j >= 0 && temp < arr[j]; j = j - gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
        // 减小步长
        gap /= 2;
    }
    return arr;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {6, 4, 7, 3, 2, 8, 9, 1, 5};
    vector<int> res = sorting4(arr);
    for_each(res.begin(), res.end(), [](int a) {
        cout << a << " ";
    });
    cout << endl;
    return 0;
}
