# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

//两数之和
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> searched;
    for (int i = 0; i < nums.size(); i++) {
        if (searched.find(target - nums[i]) != searched.end()) {
            return vector<int>{i, searched[target - nums[i]]};
        }
        searched[nums[i]] = i;
    }
    return vector<int>{};
}

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> searchmap;
    int rest;
    int count = 0;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            searchmap[nums1[i] + nums2[j]]++;
        }
    }
    for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j < nums4.size(); j++) {
            rest = -nums3[i] - nums4[j];
            if (searchmap.find(rest) != searchmap.end())
                count += searchmap[rest];
        }
    }
    return count;
}

int main() {
    vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    fourSumCount(nums1, nums2, nums3, nums4);
}
