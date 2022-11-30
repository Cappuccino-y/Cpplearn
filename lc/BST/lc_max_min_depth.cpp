# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

int getdepth(TreeNode *node) {
    if (node->left == NULL && node->right == NULL) return 1;
    int leftdepth, rightdepth, depth;
    if (node->left != NULL) leftdepth = getdepth(node->left);       // 左
    if (node->right != NULL) rightdepth = getdepth(node->right);     // 右
    if (node->left == NULL) depth = 1 + rightdepth;
    else if (node->right == NULL) depth = 1 + leftdepth;
    else depth = 1 + min(leftdepth, rightdepth); // 中
    return depth;
}

int minDepth(TreeNode *root) {
    if (!root) return 0;
    return getdepth(root);
}

int getdepth(TreeNode *node) {
    if (node == NULL) return 0;
    int leftdepth = getdepth(node->left);       // 左
    int rightdepth = getdepth(node->right);     // 右
    int depth = 1 + max(leftdepth, rightdepth); // 中
    return depth;
}

int maxDepth(TreeNode *root) {
    return getdepth(root);
}

int maxDepth_iteration(TreeNode *root) {
    queue < TreeNode * > temp;
    int depth = 0;
    if (!root) return 0;
    temp.push(root);
    while (!temp.empty()) {
        int size = temp.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = temp.front();
            temp.pop();
            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
        ++depth;
    }
    return depth;
}



