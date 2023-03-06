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


class Solution {
public:
    int maxProfit_once(vector<int> &prices) {
        int low = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);  // 取最左最小价格
            result = max(result, prices[i] - low); // 直接取最大区间利润
        }
        return result;
    }
};

int maxProfit_once(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp.back()[0];
}

int maxProfit_twice(vector<int> &prices) {
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2)));
    dp[0][1][0] = -prices[0];
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][1][0] = max(dp[i - 1][1][0], -prices[i]);
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][1] + prices[i]);
    }
    return dp.back()[0][0];
}

int maxProfit_ktimes(int k, vector<int> &prices) {
    if (prices.size() == 0) return 0;
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1)));
    for (int i = 0; i < k + 1; ++i)
        dp[0][1][i] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][1][0] = max(dp[i - 1][1][0], -prices[i]);
        for (int j = 1; j < k + 1; j++) {
            dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1] + prices[i]);
            dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j] - prices[i]);
        }
    }
    return dp.back()[0][k];
}

int maxProfit_withoutlimit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp.back()[0];
}

int maxProfit_freeze(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(4));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][3]);
        dp[i][1] = max(max(dp[i - 1][1], dp[i - 1][0] - prices[i]), dp[i - 1][3] - prices[i]);
        dp[i][2] = dp[i - 1][1] + prices[i];
        dp[i][3] = dp[i - 1][2];
    }
    return max(max(dp.back()[0], dp.back()[2]), dp.back()[3]);
}

int maxProfit_withfee(vector<int> &prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp.back()[0];
}