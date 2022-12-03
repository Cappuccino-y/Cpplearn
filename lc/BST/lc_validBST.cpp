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

bool isValidBST(TreeNode *root) {
    if (root->left && root->right) {
        if (root->left->val < root->val && root->right->val > root->val) {
            if (isValidBST(root->left) && isValidBST(root->right)) return true;
        }
        return false;
    } else if (root->left && !root->right) {
        if (root->left->val < root->val) {
            if (isValidBST(root->left)) return true;
        }
        return false;
    } else if (!root->left && root->right) {
        if (root->right->val > root->val) {
            if (isValidBST(root->right)) return true;
        }
        return false;
    }
    return true;
}

bool isValidBST(TreeNode *root) {
    traversal(root);
    for (int i = 0; i < rec.size() - 1; i++) {
        if (rec[i] >= rec[i + 1]) return false;
    }
    return true;
}

vector<int> rec;

void traversal(TreeNode *node) {
    if (node == nullptr) return;
    traversal(node->left);
    rec.push_back(node->val);
    traversal(node->right);
}

bool isValidBST(TreeNode *root) {
    if (root == NULL) return true;
    bool left = isValidBST(root->left);

    if (pre != NULL && pre->val >= root->val) return false;
    pre = root; // 记录前一个节点

    bool right = isValidBST(root->right);
    return left && right;
}