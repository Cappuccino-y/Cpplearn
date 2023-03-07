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

int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int result = 1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
        }
        if (dp[i] > result) result = dp[i];
    }
    return result;
}

