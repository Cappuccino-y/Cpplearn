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
    int dp[1005][2];

    int wiggleMaxLength(vector<int> &nums) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = dp[i][1] = 1;

            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};

int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    int curDiff = 0; // 当前一对差值
    int preDiff = 0; // 前一对差值
    int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
    for (int i = 0; i < nums.size() - 1; i++) {
        curDiff = nums[i + 1] - nums[i];
        // 出现峰值
        if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
            result++;
            preDiff = curDiff;
        }
    }
    return result;
}

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() == 1) return 1;
        int ref = -1;
        bool flag;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[0]) {
                flag = nums[i] - nums[0] > 0;
                ref = i;
                break;
            }
        }
        if (ref < 0) return 1;
        int count = 2;

        for (int i = ref + 1; i < nums.size(); ++i) {
            if (flag) {
                if (nums[i] < nums[ref]) {
                    ref = i;
                    ++count;
                    flag = !flag;
                } else {
                    ref = i;
                }
            } else {
                if (nums[i] > nums[ref]) {
                    ref = i;
                    ++count;
                    flag = !flag;
                } else {
                    ref = i;
                }
            }
        }
        return count;
    }
};

