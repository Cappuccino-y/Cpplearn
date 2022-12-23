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
    vector<vector<int>> res;
    vector<int> cur;

    void searchsub_Dup(vector<int> &nums, int startIndex) {
        res.push_back(cur);
        if (startIndex > nums.size() - 1) return;

        for (int i = startIndex; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            searchsub_Dup(nums, i + 1);
            cur.pop_back();
            while (i != nums.size() - 1 && nums[i + 1] == nums[i]) i++;
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        searchsub_Dup(nums, 0);
        return res;
    }
};

vector<vector<int>> res;
vector<int> cur;

void searchsub(vector<int> &nums, int startIndex) {
    res.push_back(cur);
    if (startIndex > nums.size() - 1) return;

    for (int i = startIndex; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        searchsub(nums, i + 1);
        cur.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int> &nums) {
    searchsub(nums, 0);
    return res;
}

int main() {
    vector<int> a{1, 2, 3};
    subsets(a);
}


