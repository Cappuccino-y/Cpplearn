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

vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> rec;
    vector<int> res(temperatures.size());
    rec.push(0);
    for (int i = 1; i < temperatures.size(); ++i) {
        while (!rec.empty() && temperatures[rec.top()] < temperatures[i]) {
            res[rec.top()] = i - rec.top();
            rec.pop();
        }
        rec.push(i);
    }
    unordered_map<int, int> as;

    return res;
}

