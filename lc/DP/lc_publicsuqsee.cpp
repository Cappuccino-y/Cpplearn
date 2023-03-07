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

bool isSubsequence(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i][j - 1];
        }
    }
    return dp.back().back() == s.size();
}

