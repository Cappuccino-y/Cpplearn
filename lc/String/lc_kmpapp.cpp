# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

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

bool repeatedSubstringPattern(string s) {
    int next[s.size()];
    pre(next, s);
    int target = next[s.size() - 1];
    if (target == 0 || s.size() % (s.size() - target) != 0) {
        return false;
    }
    return true;
}

