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
    int maxSubArray(vector<int> &nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};

int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    vector<int> dp(nums.size(), 0); // dp[i]表示包括i之前的最大连续子序列和
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
        if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
    }
    return result;
}