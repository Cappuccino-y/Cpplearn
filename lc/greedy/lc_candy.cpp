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

int candy(vector<int> &ratings) {
    vector<int> candyVec(ratings.size(), 1);
    // 从前向后
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
    }
    // 从后向前
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
    }
    // 统计结果
    int result = 0;
    for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
    return result;
}

