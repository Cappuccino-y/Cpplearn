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

bool hasPathSum(TreeNode *node, int targetSum) {
    if (node == nullptr) return false;
    if (!node->left && !node->right) {
        if (targetSum == node->val) return true;
        return false;
    }
    if (node->left) {
        if (hasPathSum(node->left, targetSum - node->val)) return true;
    }
    if (node->right) {
        if (hasPathSum(node->right, targetSum - node->val)) return true;
    }
    return false;
}

