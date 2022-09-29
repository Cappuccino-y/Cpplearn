# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int size = nums.size();
    if (size <= 3) {
        return res;
    }//排序后记得剪枝
    sort(nums.begin(), nums.end());
    int left;
    int right;
    for (int j = 0; j < size - 3; j++) {
        if (nums[j] > target && nums[j] >= 0) {
            break;
        }
        if (j > 0 && nums[j - 1] == nums[j]) {
            continue;
        }
        for (int i = j + 1; i < size - 2; i++) {
            if (nums[j] + nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i > j + 1 && nums[i - 1] == nums[i]) {
                continue;
            }
            left = i + 1;
            right = size - 1;
            while (left != right) {
                long cmp = (long) nums[i] + nums[left] + nums[right] + nums[j];
                if (cmp < target)
                    left++;
                else if (cmp > target)
                    right--;
                else if (cmp == target) {
                    if ((right < size - 1 && nums[right + 1] == nums[right]) ||
                        (left > i + 1 && nums[left - 1] == nums[left])) {
                        left++;
                        continue;
                    }
                    res.push_back(vector<int>{nums[j], nums[i], nums[left], nums[right]});
                    left++;
                }
            }
        }
    }
    return res;
}
