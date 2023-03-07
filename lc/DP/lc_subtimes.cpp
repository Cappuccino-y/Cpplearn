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

int numDistinct(string s, string t) {
    vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1));
    for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp.back().back();
}

