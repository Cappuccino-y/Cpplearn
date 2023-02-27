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

int lastStoneWeightII(vector<int> &stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); ++i) {
        sum += stones[i];
    }
    vector<int> dp(sum + 1);
    for (int i = 0; i < stones.size(); ++i) {
        for (int j = sum; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    for (int j = sum / 2; j <= sum; j++) {
        if (dp[j] == j) return abs(2 * j - sum);
    }
    return -1;
}

