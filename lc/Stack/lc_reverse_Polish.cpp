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
    bool is_Int(string s) {
        if (isdigit(s[0]))
            return true;
        if (s[0] == '-' && s.size() > 1) {
            return true;
        }
        return false;
    }

    long cal_Str(int var1, int var2, string opr) {
        if (opr == "+")
            return (long) var2 + var1;
        if (opr == "-")
            return (long) var2 - var1;
        if (opr == "*")
            return (long) var2 * var1;
        else
            return (long) var2 / var1;
    }

    int evalRPN(vector<string> &tokens) {
        int res;
        int temp1;
        int temp2;
        stack<long> rec;
        for (auto s : tokens) {
            if (is_Int(s)) {
                rec.push(stoi(s));
            } else {
                temp1 = rec.top();
                rec.pop();
                temp2 = rec.top();
                rec.pop();
                rec.push(cal_Str(temp1, temp2, s));
            }
        }
        return (int) rec.top();
    }
};

