# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

string replaceSpace(string s) {
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            res += "%20";
        } else {
            res += (s[i]);
        }
    }
    return res;
}

