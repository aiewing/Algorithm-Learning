//
//  main.cpp
//  LeetCode_344_Reverse_String
//
//  Created by Aiewing on 2018/11/8.
//  Copyright © 2018 Aiewing. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

// 暴力求解法: AC
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
class Solution5 {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};



int main(int argc, const char * argv[]) {
    
    string str = "hello";
    Solution1 *so = new Solution1();
    string res = so->reverseString(str);
    cout << res << endl;
    
    return 0;
}
