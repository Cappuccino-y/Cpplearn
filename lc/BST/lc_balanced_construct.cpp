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

TreeNode *traversal(vector<int> &nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + ((right - left) / 2);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);
    return root;
}


TreeNode *sortedArrayToBST(vector<int> &nums) {
    TreeNode *root = traversal(nums, 0, nums.size() - 1);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) return nullptr;
    int mid_index = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[mid_index]);
    vector<int> left(nums.begin(), nums.begin() + mid_index);
    vector<int> right(nums.begin() + mid_index + 1, nums.end());
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}

