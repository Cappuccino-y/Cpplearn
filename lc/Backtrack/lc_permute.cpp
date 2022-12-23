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

class Solution {
public:
    vector <vector<int>> res;
    vector<int> cur;

    void permute_nonrepeat(vector<int> &nums, int num, vector<bool> &nums_index) {
        if (num == 0) {
            res.push_back(cur);
            return;
        }

        int used[21] = {0};

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[nums[i] + 10] && !nums_index[i]) {
                cur.push_back(nums[i]);
                nums_index[i] = true;
                used[nums[i] + 10] = 1;
                permute_nonrepeat(nums, num - 1, nums_index);
                nums_index[i] = false;
                cur.pop_back();
            }
        }
        return;
    }

    vector <vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> nums_index(nums.size(), false);
        permute_nonrepeat(nums, nums.size(), nums_index);
        return res;
    }
};

using namespace std;
vector<vector<int>> res;
vector<int> cur;
int used[21] = {0};

void permute_nonrepeat(vector<int> &nums, int num) {
    if (num == 0) {
        res.push_back(cur);
        return;
    }


    for (int i = 0; i < nums.size(); ++i) {
        if (!used[nums[i] + 10]) {
            cur.push_back(nums[i]);
            used[nums[i] + 10] = 1;
            permute_nonrepeat(nums, num - 1);
            used[nums[i] + 10] = 0;
            cur.pop_back();
        }
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums) {
    permute_nonrepeat(nums, nums.size());
    return res;
}
