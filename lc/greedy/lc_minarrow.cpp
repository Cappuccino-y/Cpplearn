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

static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() == 1) return 1;
    sort(points.begin(), points.end(), cmp);
    int num = 1;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i - 1][1] < points[i][0]) num++;
        else {
            points[i][1] = min(points[i][1], points[i - 1][1]);
        }
    }
    return num;
}
