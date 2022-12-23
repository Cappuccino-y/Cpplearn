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

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    void combine(vector<int> &candidates, int left, int target) {
        if (target < 1 || left > candidates.size() - 1) {
            if (target == 0) res.push_back(cur);
            return;
        }

        int used[50] = {0};
        for (int i = left; i < candidates.size(); i++) {
            if (!used[candidates[i] - 1]) {
                cur.push_back(candidates[i]);
                used[candidates[i] - 1] = 1;
                if (target - candidates[i] > -1)
                    combine(candidates, i + 1, target - candidates[i]);
                cur.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combine(candidates, 0, target);
        return res;
    }
};

void combine(vector<int> &candidates, int left, int target) {
    if (target < 1) {
        if (target == 0) res.push_back(cur);
        return;
    }
    for (int i = left; i < candidates.size(); i++) {
        cur.push_back(candidates[i]);
        if (target - candidates[i] > -1)
            combine(candidates, i, target - candidates[i]);
        cur.pop_back();
    }
    return;
}


vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    combine(candidates, 0, target);
    return res;
}

