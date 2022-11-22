# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
#include <deque>
#include <queue>

using namespace std;

class Solution {
public:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }

        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        MyQueue rec;
        vector<int> max_val(nums.size() - k + 1);
        for (int i = 0; i < k; ++i) {
            rec.push(nums[i]);
        }
        max_val[0] = rec.front();
        for (int i = 0; i < nums.size() - k; ++i) {
            rec.push(nums[k + i]);
            rec.pop(nums[i]);
            max_val[i + 1] = rec.front();
        }
        return max_val;
    }
};

int main() {
    Solution a;
    vector<int> as{1, -1};
    a.maxSlidingWindow(as, 1);
}


