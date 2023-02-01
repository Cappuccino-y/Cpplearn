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
    bool canJump(vector<int> &nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};

bool canJump(vector<int> &nums) {
    if (nums.size() == 1) return true;
    int cur = 0;
    while (cur != nums.size() - 1) {
        int max_index;
        int max_val = -1;
        for (int i = 0; i <= nums[cur]; ++i) {
            if (i + cur == nums.size() - 1) return true;
            if (i + nums[cur + i] >= max_val) {
                max_val = i + nums[cur + i];
                max_index = cur + i;
            }
        }
        if (nums[max_index] == 0) break;
        cur = max_index;
    }
    return false;
}

int jump(vector<int> &nums) {
    int cur = 0;
    int jump_time = 0;
    while (cur != nums.size() - 1) {
        int max_index;
        int max_val = -1;
        jump_time++;
        for (int i = 0; i <= nums[cur]; ++i) {
            if (i + cur == nums.size() - 1) return jump_time;
            if (i + nums[cur + i] >= max_val) {
                max_val = i + nums[cur + i];
                max_index = cur + i;
            }
        }
        if (nums[max_index] == 0) break;
        cur = max_index;
    }
    return 0;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    canJump(nums);

}