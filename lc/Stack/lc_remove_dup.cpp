# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int fastIndex = 0, slowIndex = 0;
        for (; fastIndex < s.size(); ++fastIndex) {
            if (slowIndex > 0 && s[slowIndex - 1] == s[fastIndex]) {
                if (slowIndex > 1 | fastIndex == s.size() - 1)
                    slowIndex--;
                else
                    s[slowIndex - 1] = s[++fastIndex];
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        s.resize(slowIndex);
        return s;
    }

    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }

};

