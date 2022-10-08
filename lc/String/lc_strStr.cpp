# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

//使用KMP算法
int strStr_question(string haystack, string needle) {
    int temp;
    for (int i = 0; i < haystack.size(); ++i) {
        temp = i;
        for (int j = 0; j < needle.size() && temp < haystack.size(); ++j) {
            if (haystack[temp] != needle[j]) {
                break;
            }
            temp++;
        }
        if ((temp - i) == needle.size()) {
            return i;
        }
    }
    return -1;
}

void getNext(int *next, const string &s) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
            j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

void pre(int *a, string &s) {
    int j = 0;
    a[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (j > 0 && s[j] != s[i]) {
            j = a[j - 1];
        }
        if (s[j] == s[i]) {
            j++;
        }
        a[i] = j;
    }
}

int strStr_my(string haystack, string needle) {
    int next[needle.size()];
    pre(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == needle.size()) {
            return i - needle.size() + 1;
        }
    }
    return -1;
}


int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = -1; // // 因为next数组里记录的起始位置为-1
    for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
        while (j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
            j = next[j]; // j 寻找之前匹配的位置
        }
        if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
            j++; // i的增加在for循环里
        }
        if (j == (needle.size() - 1)) { // 文本串s里出现了模式串t
            return (i - needle.size() + 1);
        }
    }
    return -1;
}
