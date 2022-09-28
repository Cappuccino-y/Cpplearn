# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    unordered_set<int> rec;
    unordered_map<string, vector<int>> res;
    vector<vector<int>> result;
    vector<int> temp;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (rec.find(-nums[i] - nums[j]) != rec.end()) {
                temp = vector<int>{nums[i], nums[j], -nums[i] - nums[j]};
                sort(temp.begin(), temp.end());
                string m = to_string(temp[0]) + to_string(temp[1]) + to_string(temp[2]);
                res[m] = temp;
            }
        }
        rec.insert(nums[i]);
    }
    for (auto it = res.begin(); it != res.end(); it++) {
        result.push_back(it->second);
    }
    return result;
}

