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

int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> temp;
    temp.push(root);
    int res;
    while (!temp.empty()) {
        int size = temp.size();
        res = temp.front()->val;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = temp.front();
            temp.pop();
            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }
    return res;
}

int maxDepth = INT_MIN;
int result;

void traversal(TreeNode *root, int depth) {
    if (root->left == NULL && root->right == NULL) {
        if (depth > maxDepth) {
            maxDepth = depth;
            result = root->val;
        }
        return;
    }
    if (root->left) {
        depth++;
        traversal(root->left, depth);
        depth--; // 回溯
    }
    if (root->right) {
        depth++;
        traversal(root->right, depth);
        depth--; // 回溯
    }
    return;
}

int findBottomLeftValue(TreeNode *root) {
    traversal(root, 0);
    return result;
}