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

void combine_recur(int left, int right, int num, vector<int> &temp) {
    if (num == 0) {
        res.push_back(temp);
        return;
    }
    for (int i = left; i < right + 1; ++i) {
        temp.push_back(i);
        combine_recur(i + 1, right + 1, num - 1, temp);
        temp.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    combine_recur(1, n - k + 1, k, temp);
    return res;
}

int main() {
    vector<vector<int>> res = combine(10, 3);
    int m=3;
}


