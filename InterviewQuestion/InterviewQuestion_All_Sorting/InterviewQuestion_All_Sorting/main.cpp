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
/// 时间复杂度：O(n^2)
/// 空间复杂度：O(1)
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
/// 时间复杂度：O(n^2)
/// 空间复杂度：O(1)
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
/// 时间复杂度：O(n^2)
/// 空间复杂度：O(1)
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
/// 时间复杂度：O(n^1.3)
/// 空间复杂度：O(1)
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

/// 快速排序
/// 时间复杂度：O(n*log2n)
/// 空间复杂度：O(log2n)
void sorting5(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int left = low;
    int right = high;
    int key = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= key) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= key) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = key;
    sorting5(arr, low, left - 1);
    sorting5(arr, left + 1, high);
}

/// 归并排序 非递归
/// 时间复杂度：O(n*log2n)
/// 空间复杂度：O(n)
vector<int> sorting6(vector<int> arr) {
    // 现在使用非递归的方法
    // 先设定步长 从2开始 每次排序结束之后 *2
    long count = arr.size();
    int step = 2;
    vector<vector<int>> res;
    for (int i = 0; i < count; i += step) {
        vector<int> subArr;
        if (i > count - 2) {
            subArr.push_back(arr[i]);
        } else {
            subArr.push_back(min(arr[i], arr[i + 1]));
            subArr.push_back(max(arr[i], arr[i + 1]));
        }
        res.push_back(subArr);
    }
    
    // 接下来两个一组 两个一组的合并
    while (res.size() > 1) {
        vector<vector<int>> tempRes;
        count = res.size();
        for (int i = 0; i < res.size(); i += step) {
            vector<int> subArr;
            if (i > count - 2) {
                tempRes.push_back(res[i]);
            } else {
                // 两个数组归并为一个数组
                int one = 0;
                int two = 0;
                vector<int> oneArr = res[i];
                vector<int> twoArr = res[i + 1];
                while (one < oneArr.size() && two < twoArr.size()) {
                    if (oneArr[one] < twoArr[two]) {
                        subArr.push_back(oneArr[one++]);
                    } else {
                        subArr.push_back(twoArr[two++]);
                    }
                }
                
                while (one < oneArr.size()) {
                    subArr.push_back(oneArr[one++]);
                }
                
                while (two < twoArr.size()) {
                    subArr.push_back(twoArr[two++]);
                }
                tempRes.push_back(subArr);
            }
            
        }
        res = tempRes;
    }
    return res.front();
}


vector<int> merge7(vector<int> left, vector<int> right) {
    vector<int> res;
    // 两个数组归并为一个数组
    int one = 0;
    int two = 0;
    while (one < left.size() && two < right.size()) {
        if (left[one] < right[two]) {
            res.push_back(left[one++]);
        } else {
            res.push_back(right[two++]);
        }
    }
    
    while (one < left.size()) {
        res.push_back(left[one++]);
    }
    
    while (two < right.size()) {
        res.push_back(right[two++]);
    }
    return res;
}

/// 归并排序 递归
/// 时间复杂度：O(n*log2n)
/// 空间复杂度：O(n)
vector<int> sorting7(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    // 先将数组分为两个
    int mid = arr.size() / 2;
    vector<int> left, right;
    copy(arr.begin(), arr.begin() + mid, back_inserter(left));
    copy(arr.begin() + mid, arr.end(), back_inserter(right));
    
    return merge7(sorting7(left), sorting7(right));
}



int main(int argc, const char * argv[]) {
    vector<int> arr = {6, 4, 7, 3, 2, 8, 9, 1, 5};
    vector<int> res = sorting7(arr);
//    sorting5(arr, 0, arr.size() - 1);
    for_each(res.begin(), res.end(), [](int a) {
        cout << a << " ";
    });
    cout << endl;
    return 0;
}
