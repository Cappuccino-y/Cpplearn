#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

//可以使用数组作为映射
bool isAnagram_my(string s, string t) {
    map<char, int> records_s;
    map<char, int> records_t;
    int length_s = s.size();
    int length_t = t.size();
    if (length_s != length_t) {
        return false;
    }
    for (int i = 0; i < length_s; ++i) {
        if (records_s.find(s[i]) == records_s.end())
            records_s[s[i]] = 1;
        else {
            ++records_s[s[i]];
        }

        if (records_t.find(t[i]) == records_s.end())
            records_t[t[i]] = 1;
        else {
            ++records_t[t[i]];
        }
    }
    for (auto it = records_s.begin(); it != records_s.end(); it++) {
        if (records_t.find(it->first) == records_s.end()) {
            return false;
        }
        if (it->second != records_t[it->first]) {
            return false;
        }
    }
    return true;
}

bool isAnagram(string s, string t) {
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
        record[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
            return false;
        }
    }
    // record数组所有元素都为零0，说明字符串s和t是字母异位词
    return true;
}

int main() {
}
