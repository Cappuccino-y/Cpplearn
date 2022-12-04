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

int min_val = INT_MAX;
TreeNode *pre = nullptr;

int getMinimumDifference(TreeNode *root) {
    if (root == nullptr) return INT_MAX;
    if (root->left) getMinimumDifference(root->left);
    if (pre) min_val = min(abs(pre->val - root->val), min_val);
    pre = root;
    if (root->right) getMinimumDifference(root->right);
    return min_val;
}
