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

int numSquares(int n) {
    vector<int> rec;
    for (int i = 1; i <= 100; ++i) {
        rec.push_back(i * i);
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    string as;
    as.su
    as.rend
    for (int i = 0; i < rec.size(); ++i) {
        for (int j = rec[i]; j <= n; ++j) {
            if (dp[j - rec[i]] != INT_MAX) dp[j] = min(dp[j - rec[i]] + 1, dp[j]);
        }
    }
    return dp[n];
}

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 遍历物品
            for (int j = i * i; j <= n; j++) { // 遍历背包
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};