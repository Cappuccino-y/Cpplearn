#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> intersectionmy(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> records;
    unordered_set<int> result;
    vector<int> res;
    for (int i = 0; i < nums1.size(); ++i) {
        records.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++) {
        if (records.find(nums2[i]) != records.end()) {
            result.insert(nums2[i]);
        }
    }
    res.assign(result.begin(), result.end());
    return res;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2) {
        // 发现nums2的元素 在nums_set里又出现过
        if (nums_set.find(num) != nums_set.end()) {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}

vector<int> intersect_howmanytimes(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_map<int, int> result_map; // 存放结果，之所以用set是为了给结果集去重
    unordered_map<int, int> nums_map;
    for (int num :nums1) {
        nums_map[num]++;
    }
    for (int num : nums2) {
        if (nums_map.find(num) != nums_map.end()) {
            if (result_map[num] < nums_map[num])
                result_map[num]++;
        }
    }
    for (auto it = result_map.begin(); it != result_map.end(); it++) {
        for (int i = 0; i < it->second; ++i) {
            res.push_back(it->first);
        }
    }
    return res;
}