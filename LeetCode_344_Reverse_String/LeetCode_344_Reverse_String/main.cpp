//
//  main.cpp
//  LeetCode_344_Reverse_String
//
//  Created by Aiewing on 2018/11/8.
//  Copyright © 2018 Aiewing. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <sys/time.h>

using namespace std;

// 暴力求解法: AC
// 例子中字符串10000次测试，平均时间：12毫秒
// 时间复杂度为O(N)
// 空间复杂度为O(N)
// 优点：简单易懂
// 缺点：算法的运行时间较长，使用的额外内存较多
class Solution1 {
public:
    string reverseString(string s) {
        string res;
        for (int i = int(s.size() - 1); i >= 0 ; i--)
            res.push_back(s[i]);
        return res;
    }
};


// 首尾易位法1: AC
// 例子中字符串10000次测试，平均时间：7-8毫秒
// 时间复杂度为O(N)
// 空间复杂度为O(1)
// 优点：和上面的算法时间复杂度虽然一样，但是时间比上面少了一半左右，也不需要额外的空间。
// 缺点：下标的操作没有指针操作那么快。
class Solution2 {
public:
    string reverseString(string s) {
        long count = s.size();
        for (int i = 0; i < (count / 2); i++)
            swap(s[i], s[count - i - 1]);
        return s;
    }
};

// 首尾易位法2: AC
// 例子中字符串10000次测试，平均时间：8-11毫秒
// 时间复杂度为O(N)
// 空间复杂度为O(1)
// 优点：和上面的算法差不多。
// 缺点：下标的操作没有指针操作那么快。
class Solution3 {
public:
    string reverseString(string s) {
        long left = 0;
        long right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
        return s;
    }
};

// 首尾易位法3-C语言骚操作: AC
// 例子中字符串10000次测试，平均时间：4-5毫秒
// 时间复杂度为O(N)
// 空间复杂度为O(1)
// 优点：使用指针操作数据，算法的运行时间更短了。
// 缺点：代码比较复杂。
class Solution4 {
public:
    string reverseString(string s) {
        char *str = (char *)s.c_str();
        char *start = str;
        char *left = str;
        char ch;
        // 先找到字符串的末尾
        while (*str++);
        str -= 2;
        
        while (left < str) {
            ch = *left;
            *left++ = *str;
            *str-- = ch;
        }
        return start;
    }
};

// C++系统交换法: AC
// 例子中字符串10000次测试，平均时间：4-5毫秒
// 未知内部实现，猜测是和上面一样的指针操作。
class Solution5 {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int64_t getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


int main(int argc, const char * argv[]) {
    
    string str = "hellogfdgfdsgfdgfdgfdgfdgfdgfdgfdgfkdhg'fdgfd;jgfdghfdgfdlkghlfdhgkfhdgfkdgjkfhdhk;";
    Solution5 *so = new Solution5();
    long startTime = getCurrentTime();
    for (int i = 0; i < 10000; i++) {
        string res = so->reverseString(str);
    }
    long endTime = getCurrentTime();
    long time = endTime - startTime;
    cout << time << endl;
    
//    cout << res << endl;
    return 0;
}
