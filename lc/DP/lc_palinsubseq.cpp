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

int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int res = 1;
    for (int i = s.size() - 1; i > -1; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) dp[i][j] = j - i + 1;
                else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            } else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
        }
    }
    return res;
}
