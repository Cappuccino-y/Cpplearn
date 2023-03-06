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

bool is_equal(string &s1, string &s2, int n1, int n2) {
    for (int i = 0; i < n2; ++i) {
        if (s1[i] != s2[n1 + i]) return false;
    }
    return true;
}

bool wordBreak(string s, vector<string> &wordDict) {
    vector<int> dp(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < wordDict.size(); ++j) {
            if (i >= wordDict[j].size() && is_equal(wordDict[j], s, dp[i - wordDict[j].size()], wordDict[j].size())) {
                dp[i] = max(int(dp[i - wordDict[j].size()] + wordDict[j].size()), dp[i]);
            }
        }
    }
    return dp[s.size()] == s.size();
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    wordBreak(s, wordDict);
}

