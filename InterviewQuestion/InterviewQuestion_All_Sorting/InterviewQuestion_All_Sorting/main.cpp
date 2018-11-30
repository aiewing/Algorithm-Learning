//
//  main.cpp
//  InterviewQuestion_All_Sorting
//
//  Created by 舒毅文 on 2018/11/20.
//  Copyright © 2018 舒毅文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 题目
    列举所有的排序并分析
 */


/// 冒泡排序
/// 时间复杂度：O(n^2)
/// 空间复杂度：O(1)
vector<int> bubbleSort1(vector<int> arr) {
    int count = arr.size();
    for (int i = 1; i < count; i++) {
        for (int j = 1; j < count - i; j++) {
            if (arr[j] < arr[j - 1]) {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    return arr;
}

vector<int> bubbleSort2(vector<int> arr) {
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
vector<int> selectionSort(vector<int> arr) {
    int minIndex;
    for (int i = 0; i < arr.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            // 先找出一个最小的数
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        // 和第i位交换
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

/// 插入排序
/// 时间复杂度：O(n^2)
/// 空间复杂度：O(1)
vector<int> insertionSort(vector<int> arr) {
    // 已经排好序的位置
    int sortedIndex = 0;
    int current;
    // 遍历未排序的数组
    for (int i = 1; i < arr.size(); i++) {
        current = arr[i];
        // 把取出来的数据插入到已排序的数组中
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
vector<int> shellSort(vector<int> arr) {
    int step = arr.size() / 2;
    while(step >= 1) {
        // 把距离为step的元素编为一组 扫描所有组
        for (int i = step; i < arr.size(); i++) {
            int j = 0;
            int temp = arr[i];
            
            // 对距离为gap的元素组进行排序
            for (j = i - step; j >= 0 && temp < arr[j]; j = j - step) {
                arr[j + step] = arr[j];
            }
            arr[j + step] = temp;
        }
        // 减小步长
        step /= 2;
    }
    return arr;
}

/// 快速排序
/// 时间复杂度：O(n*log2n)
/// 空间复杂度：O(log2n)

void quickSorting(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    // 先保存左右点
    int left = low;
    int right = high;
    // 默认关键值为数组的最左边的点
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
    quickSorting(arr, low, left - 1);
    quickSorting(arr, left + 1, high);
}

vector<int> quickSort(vector<int> arr) {
    quickSorting(arr, 0, arr.size() - 1);
    return arr;
}

/// 归并排序 非递归
/// 时间复杂度：O(n*log2n)
/// 空间复杂度：O(n)
vector<int> mergeSort1(vector<int> arr) {
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


vector<int> merge(vector<int> left, vector<int> right) {
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
vector<int> mergeSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    // 先将数组分为两个
    int mid = arr.size() / 2;
    vector<int> left, right;
    copy(arr.begin(), arr.begin() + mid, back_inserter(left));
    copy(arr.begin() + mid, arr.end(), back_inserter(right));
    
    return merge(mergeSort(left), mergeSort(right));
}

/// 计数排序
/// 时间复杂度：
/// 空间复杂度：
vector<int> countingSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    // 先找出排序数组中的最大和最小的元素
    int maxInt = arr.front();
    int minInt = arr.front();
    for (int i = 0; i < arr.size(); i++) {
        maxInt = max(arr[i], maxInt);
        minInt = min(arr[i], minInt);
    }
    
    // 创建一个数组可以承载最小到最大值中的所有的元素。
    vector<int> bucket(maxInt - minInt + 1);
    for (int i = 0; i < arr.size(); i++) {
        bucket[arr[i] - minInt]++;
    }
    
    int index = 0;
    for (int i = 0; i < bucket.size(); i++) {
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }
    return arr;
}

/// 桶排序
/// 时间复杂度：
/// 空间复杂度：
vector<int> bucketSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    // 先找出排序数组中的最大和最小的元素
    int maxInt = arr.front();
    int minInt = arr.front();
    for (int i = 0; i < arr.size(); i++) {
        maxInt = max(arr[i], maxInt);
        minInt = min(arr[i], minInt);
    }
    
    // 初始化桶
    // 桶大小
    int bucketSize = 5;
    // 桶个数 向上取整
    int bucketCount = ceil((maxInt - minInt + 1) / 5.0);
    vector<vector<int>> bucket(bucketCount);
    
    for (int i = 0; i < arr.size(); i++) {
        // 判断放到哪一个桶中
        int index = (arr[i] - minInt) / bucketSize;
        bucket[index].push_back(arr[i]);
    }
    
    // 分别对每个桶中的数据快速排序
    arr.resize(0);
    for (int i = 0; i < bucket.size(); i++) {
        if (bucket[i].size() > 0) {
            quickSort(bucket[i]);
            arr.insert(arr.end(), bucket[i].begin(), bucket[i].end());
        }
    }
    return arr;
}

// 堆调整
int len;
void adjustHeap(vector<int> &arr, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int top = i;
    
    if (left < len && arr[left] > arr[top]) {
        top = left;
    }
    if (right < len && arr[right] > arr[top]) {
        top = right;
    }
    
    if (top != i) {
        int temp = arr[i];
        arr[i] = arr[top];
        arr[top] = temp;
        adjustHeap(arr, top);
    }
}

// 创建大顶堆
void buildHeap(vector<int> &arr) {
    // 现在是一个无序的普通的堆
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i);
    }
}

/// 堆排序
/// 时间复杂度：
/// 空间复杂度：
vector<int> heapSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    len = arr.size();
    buildHeap(arr);
    
    for (int i = arr.size() - 1; i > 0; i--) {
        // 交换
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        // 需要实时记录一个len
        len--;
        // 重新排列成为大顶堆 从上到下
        adjustHeap(arr, 0);
    }
    return arr;
}

/// 基数排序
/// 时间复杂度：
/// 空间复杂度：
vector<int> radixSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    
    // 先找出排序数组中的最大和最小的元素
    int maxInt = arr.front();
    for (int i = 0; i < arr.size(); i++) {
        maxInt = max(arr[i], maxInt);
    }
    
    // 求出最大的位数
    int maxDigit = 1;
    while (maxInt / 10 > 0) {
        maxInt = maxInt / 10;
        maxDigit++;
    }
    
    for (int i = 0; i < maxDigit; i++) {
        // 创建一个数组为10的数组
        vector<vector<int>> bucket(10);
        // 分别放到不同的桶中
        for (int j = 0; j < arr.size(); j++) {
            // 计算i个位置的数
            int num = (arr[j] % (int)pow(10, i + 1)) / (int)pow(10, i);
            bucket[num].push_back(arr[j]);
        }
        
        // 把桶中的数据重新取出
        arr.resize(0);
        for (int j = 0; j < bucket.size(); j++) {
            if (bucket[j].size() > 0) {
                for (int k = 0; k < bucket[j].size(); k++) {
                    arr.push_back(bucket[j][k]);
                }
            }
        }
    }
    return arr;
}

int main(int argc, const char * argv[]) {
//    vector<int> arr = {6, 4, 7, 3, 2, 8, 9, 1, 5, 11, 111};
    vector<int> arr = {4, 3, 5, 4, 6};
    vector<int> res = quickSort(arr);
//    sorting5(arr, 0, arr.size() - 1);
    for_each(res.begin(), res.end(), [](int a) {
        cout << a << " ";
    });
    cout << endl;
    return 0;
}
