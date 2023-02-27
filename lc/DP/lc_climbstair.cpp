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
    int minCostClimbingStairs(vector<int> cost) {
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
            dp0 = dp1; // 记录一下前两位
            dp1 = dpi;
        }
        return dp1;
    }
};

int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() == 1) return cost[0];
    if (cost.size() == 2) return min(cost[0], cost[1]);
    if (cost.size() == 3) return min(cost[1], min(cost[0], cost[1]) + cost[2]);
    int dp0 = min(cost[0], cost[1]);
    int dp1 = min(cost[1], dp0 + cost[2]);
    for (int i = 3; i < cost.size(); ++i) {
        int next = min(dp0 + cost[i - 1], dp1 + cost[i]);
        dp0 = dp1;
        dp1 = next;
    }
    return dp1;
}

int main() {
    Solution *as = new Solution();
    cout << as->minCostClimbingStairs(vector<int>{3, 1231, 123});
}

