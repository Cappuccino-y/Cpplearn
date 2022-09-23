#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;


string minWindow(string s, string t) {
    int length = s.length();
    int i = 0;
    int j = 0;
    int index;
    int len;
    int min_len = INT_MAX;
    string tmp = t;
    string result = "";
    map<char, int> info;
    for (int k = 0; k < t.length(); ++k) {
        if (info[t[k]] == 0)
            info[t[k]] = 1;
        else
            info[t[k]] += 1;
    }
    for (; j < length; ++j) {
        if (t.find(s[j]) != string::npos) {
            info[s[j]] -= 1;
            if (tmp.find(s[j]) != string::npos)
                tmp.erase(tmp.find(s[j]), 1);
        }
        while (tmp == "") {
            if (t.find(s[i]) != string::npos) {
                if (info[s[i]] == 0) {
                    info[s[i]] += 1;
                    tmp += s[i];
                    len = j - i + 1;//不可移动了
                    if (len < min_len) {
                        min_len = len;
                        index = i;
                    }
                    i++;
                    break;
                }
                info[s[i]] += 1;
            }
            i++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(index, min_len);
}

int main() {
    string s = "ADOBECODEBANC";
    cout << minWindow(s, "ABC") << endl;
};
