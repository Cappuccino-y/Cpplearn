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
string cur;
vector<string> dic = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void numbercombine(string digits, int index) {
    if (index == digits.size()) {
        res.push_back(cur);
        return;
    }
    for (auto i : dic[digits[index] - '2']) {
        cur.push_back(i);
        numbercombine(digits, index + 1);
        cur.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits) {
    if (digits == "") return res;
    numbercombine(digits, 0);
    return res;
}

