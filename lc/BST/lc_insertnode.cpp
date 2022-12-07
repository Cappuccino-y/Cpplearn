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

void insertBST(TreeNode *node, int val) {
    if (node == nullptr) return;
    if (!node->left && val < node->val) {
        node->left = new TreeNode(val);
        return;
    }
    if (!node->right && val > node->val) {
        node->right = new TreeNode(val);
        return;
    }

    if (val < node->val) insertIntoBST(node->left, val);
    if (val > node->val) insertIntoBST(node->right, val);
    return;
}

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    insertBST(root, val);
    return root;
}

