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

//recursive_postorder
TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) return nullptr;
    int max_val = INT_MIN;
    int max_index;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > max_val) {
            max_val = nums[i];
            max_index = i;
        }
    }
    TreeNode *root = new TreeNode(max_val);
    vector<int> nums_left(nums.begin(), nums.begin() + max_index);
    vector<int> nums_right(nums.end() - (size - nums_left.size() - 1), nums.end());

    root->left = constructMaximumBinaryTree(nums_left);
    root->right = constructMaximumBinaryTree(nums_right);

    return root;

}

