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
    int largestRectangleArea(vector<int> &heights) {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();

        // 记录每个柱子 左边第一个小于该柱子的下标
        minLeftIndex[0] = -1; // 注意这里初始化，防止下面while死循环
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // 这里不是用if，而是不断向左寻找的过程
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        // 记录每个柱子 右边第一个小于该柱子的下标
        minRightIndex[size - 1] = size; // 注意这里初始化，防止下面while死循环
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            // 这里不是用if，而是不断向右寻找的过程
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        // 求和
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};

int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    heights.insert(heights.begin(), 0); // 数组头部加入元素0
    heights.push_back(0); // 数组尾部加入元素0
    st.push(0);
    int result = 0;
    for (int i = 1; i < heights.size(); i++) {
        while (heights[i] < heights[st.top()]) {
            int mid = st.top();
            st.pop();
            int w = i - st.top() - 1;
            int h = heights[mid];
            result = max(result, w * h);
        }
        st.push(i);
    }
    return result;
}

int main() {
    Solution as;
    vector<int> heights{2, 1, 5, 6, 2, 3};
    largestRectangleArea(heights);
}
