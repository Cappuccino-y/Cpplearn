# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

void reverseString(vector<char> &s) {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
        swap(s[i], s[j]);
    }
}

void reverseString_my(vector<char> &s) {
    int left = 0;
    int right = s.size() - 1;
    char temp;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

string reverseStr_my(string s, int k) {
    int left;
    int right;
    bool mode = true;
    for (int i = k - 1; i < s.length(); i += k) {
        if (mode) {
            right = i;
            left = i - k + 1;
            while (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }
        mode = !mode;
    }
    if (!mode || s.length() % k == 0) {
        return s;
    }
    right = s.length() - 1;
    left = (s.length() / k) * k;
    while (left < right) {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
    return s;
}

string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= s.size()) {
            reverse(s.begin() + i, s.begin() + i + k);
        } else {
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.end());
        }
    }
    return s;
}

int main() {
    string s = "a";
    int k = 2;
    reverseStr(s, k);
}