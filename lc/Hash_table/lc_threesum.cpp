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
    vector<vector<int>> res;
    int size = nums.size();
    if (size <= 2) {
        return res;
    }
    sort(nums.begin(), nums.end());
    int left;
    int right;
    for (int i = 0; i < size - 2; i++) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        left = i + 1;
        right = size - 1;
        while (left != right) {
            if (nums[i] + nums[left] + nums[right] < 0)
                left++;
            else if (nums[i] + nums[left] + nums[right] > 0)
                right--;
            else if (nums[i] + nums[left] + nums[right] == 0) {
                if ((right < size - 1 && nums[right + 1] == nums[right]) ||
                    (left > i + 1 && nums[left - 1] == nums[left])) {
                    left++;
                    continue;
                }
                res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
            }
        }
    }
    return res;
}//简单通过

vector<vector<int>> threeSum_initiall(vector<int> &nums) {
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

int main() {
    vector<int> asd = {1, 0, -1};
    threeSum(asd);
}
