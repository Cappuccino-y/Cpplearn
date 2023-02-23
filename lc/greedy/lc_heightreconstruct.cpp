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

static bool compare(vector<int> item1, vector<int> item2) {
    if (item1[0] > item2[0]) return true;
    else if (item1[0] < item2[0]) return false;
    else {
        if (item1[1] < item2[1]) return true;
        else return false;
    }
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> res;
    sort(people.begin(), people.end(), compare);
    for (int i = 0; i < people.size(); ++i) {
        res.insert(res.begin() + people[i][1], people[i]);
    }
    return res;
}

