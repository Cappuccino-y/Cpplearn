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

int trap(vector<int> &height) {
    int sum = 0;
    for (int i = 0; i < height.size(); i++) {
        // 第一个柱子和最后一个柱子不接雨水
        if (i == 0 || i == height.size() - 1) continue;
        int rHeight = height[i]; // 记录右边柱子的最高高度
        int lHeight = height[i]; // 记录左边柱子的最高高度
        for (int r = i + 1; r < height.size(); r++) {
            if (height[r] > rHeight) rHeight = height[r];
        }
        for (int l = i - 1; l >= 0; l--) {
            if (height[l] > lHeight) lHeight = height[l];
        }
        int h = min(lHeight, rHeight) - height[i];
        sum += h; // 注意只有h大于零的时候，在统计到总和中
    }
    return sum;
}

int trap_doubleend(vector<int> &height) {
    if (height.size() <= 2) return 0;
    vector<int> maxLeft(height.size(), 0);
    vector<int> maxRight(height.size(), 0);
    int size = maxRight.size();

    // 记录每个柱子左边柱子最大高度
    maxLeft[0] = height[0];
    for (int i = 1; i < size; i++) {
        maxLeft[i] = max(height[i], maxLeft[i - 1]);
    }
    // 记录每个柱子右边柱子最大高度
    maxRight[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        maxRight[i] = max(height[i], maxRight[i + 1]);
    }
    // 求和
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int count = min(maxLeft[i], maxRight[i]) - height[i];
        if (count > 0) sum += count;
    }
    return sum;
}

int trap_stack(vector<int> &height) {
    stack<int> rec;
    rec.push(0);
    int res = 0;
    for (int i = 1; i < height.size(); ++i) {
        while (!rec.empty() && height[rec.top()] < height[i]) {
            int mid = rec.top();
            rec.pop();
            if (!rec.empty()) {
                int h = min(height[rec.top()], height[i]) - height[mid];
                int w = i - rec.top() - 1; // 注意减一，只求中间宽度
                res += h * w;
            }
        }
        rec.push(i);
    }
    return res;
}


int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trap_stack(height);
}