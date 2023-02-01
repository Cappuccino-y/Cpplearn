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
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        int buy_price;
        bool occupied = false;
        int diff;
        for (int i = 0; i < prices.size() - 1; i++) {
            diff = prices[i + 1] - prices[i];
            if (diff > 0 && !occupied) {
                buy_price = prices[i];
                occupied = true;
            } else if (occupied && diff < 0) {
                profit += prices[i] - buy_price;
                occupied = false;
            }
        }
        if (occupied) profit += prices[prices.size() - 1] - buy_price;
        return profit;
    }
};

int maxProfit(vector<int> &prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        result += max(prices[i] - prices[i - 1], 0);
    }
    return result;
}