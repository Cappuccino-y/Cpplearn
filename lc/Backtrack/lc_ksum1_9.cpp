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
vector<int> temp;

void search_trackback(int left, int right, int num, int sum) {
    if (num == 0) {
        if (sum == 0)
            res.push_back(temp);
        return;
    }

    for (int i = left; i < right + 1; ++i) {
        if (num != 1 && (sum - i) / (num - 1) > left - 1 && (sum - i) / (num - 1) < 10 || num == 1) {
            temp.push_back(i);
            search_trackback(i + 1, right + 1, num - 1, sum - i);
            temp.pop_back();
        }
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    search_trackback(1, 9 - k + 1, k, n);
    return res;
}

