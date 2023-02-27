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

int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    vector<vector<int>> rec(strs.size(), vector<int>(2));
    for (int i = 0; i < strs.size(); ++i) {
        for (char m:strs[i]) {
            rec[i][m - '0']++;
        }
    }
    for (int i = 0; i < strs.size(); ++i) {
        for (int j = m; j >= rec[i][0]; j--) {
            for (int k = n; k >= rec[i][1]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - rec[i][0]][k - rec[i][1]] + 1);
            }
        }
    }
    return dp[m][n];
}

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 默认初始化0
        for (string str : strs) { // 遍历物品
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};