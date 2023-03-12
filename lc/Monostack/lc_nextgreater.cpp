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

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> rec;
    rec.push(0);
    vector<int> res(nums1.size(), -1);
    unordered_map<int, int> umap;
    for (int i = 0; i < res.size(); ++i) umap[nums1[i]] = i;
    for (int i = 1; i < nums2.size(); i++) {
        while (!rec.empty() && nums2[rec.top()] < nums2[i]) {
            if (umap.count(nums2[rec.top()])) res[umap[nums2[rec.top()]]] = nums2[i];
            rec.pop();
        }
        rec.push(i);
    }
    return res;

}

vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> result(nums.size(), -1);
    if (nums.size() == 0) return result;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < nums.size() * 2; i++) {
        while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
            result[st.top()] = nums[i % nums.size()];
            st.pop();
        }
        st.push(i % nums.size());
    }
    return result;
}
