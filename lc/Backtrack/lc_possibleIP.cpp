# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
# include <queue>
# include <stack>

using namespace std;
vector<string> res;
vector<int> insertIndex;

bool valid(string &s) {
    if (s.size() > 3 || stoi(s) > 255) return false;
    if (s[0] == '0' && s.size() > 1) return false;
    return true;
}

void IPconstruct(string &s, int startIndex, int num) {
    if (startIndex > s.size() - 1) {
        return;
    }
    if (num == 0) {
        string m = s.substr(startIndex, s.size() - startIndex);
        if (valid(m)) {
            string result = s;
            for (int i = 0; i < insertIndex.size(); ++i) {
                result.insert(insertIndex[i] + i, ".");
            }
            res.push_back(result);
        }
        return;
    }

    for (int step = 1; step < 4; ++step) {
        string m = s.substr(startIndex, step);
        if (valid(m)) {
            insertIndex.push_back(startIndex + step);
            IPconstruct(s, startIndex + step, num - 1);
            insertIndex.pop_back();
        }
    }
    return;
}

vector<string> restoreIpAddresses(string s) {
    IPconstruct(s, 0, 3);
    return res;
}

int main() {
    vector<string> res = restoreIpAddresses("25525511135");
    int m = 3;
}


