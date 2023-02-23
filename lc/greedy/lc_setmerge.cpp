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

static bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() == 1) return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> res(1, intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > res.back()[1]) {
            res.push_back(intervals[i]);
        } else {
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        }
    }
    return res;
}

