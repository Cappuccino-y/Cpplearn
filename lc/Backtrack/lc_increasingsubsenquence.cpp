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
vector<vector<int>> res;
vector<int> cur;

void findSub(vector<int> &nums, int startIndex) {
    if (cur.size() > 1) {
        res.push_back(cur);
    }
    if (startIndex > nums.size() - 1) return;

    int used[201] = {0};

    for (int i = startIndex; i < nums.size(); ++i) {
        if (used[nums[i] + 100]) continue;
        if (cur.empty() || nums[i] >= cur.back()) {
            cur.push_back(nums[i]);
            used[nums[i] + 100] = 1;
            findSub(nums, i + 1);
            cur.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
    findSub(nums, 0);
    return res;
}

int main() {
    vector<int> as{1, 2, 3, 1, 1, 1, 1, 1};
    vector<vector<int>> k = findSubsequences(as);
    int m = 3;
}