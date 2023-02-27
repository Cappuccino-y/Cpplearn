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

bool canPartition(vector<int> &nums) {
    int target = 0;
    for (int num : nums) {
        target += num;
    }
    if (target % 2 == 1) return false;
    target = target / 2;
    vector<int> dp(target + 1);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= nums[i]; --j) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if (dp[target] == target) return true;
    return false;
}

