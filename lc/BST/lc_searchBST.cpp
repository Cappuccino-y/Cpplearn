# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
# include <stack>
# include <queue>

using namespace std;

TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr) return nullptr;
    if (root->val == val) return root;
    TreeNode *res = searchBST(root->left, val);
    if (res) return res;
    res = searchBST(root->right, val);
    if (res) return res;
    return res;
}

TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr || root->val == val) return root;
    TreeNode *res = nullptr;
    if (root->val < val) res = searchBST(root->right, val);
    if (root->val > val) res = searchBST(root->left, val);
    return res;
}