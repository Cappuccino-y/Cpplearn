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

int sumOfLeftLeaves(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;

    int leftValue = sumOfLeftLeaves(root->left);    // 左
    if (root->left && !root->left->left && !root->left->right) { // 左子树就是一个左叶子的情况
        leftValue = root->left->val;
    }
    int rightValue = sumOfLeftLeaves(root->right);  // 右

    int sum = leftValue + rightValue;               // 中
    return sum;
}

int sumOfLeftLeaves(TreeNode *root) {
    if (root == NULL) return 0;
    int leftValue = 0;
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        leftValue = root->left->val;
    }
    return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

void recursive_sum(TreeNode *node, int &num, int dir = 1) {
    if (node->left == nullptr && node->right == nullptr) {
        if (dir == 0)
            num += node->val;
        return;
    }
    if (node->left) recursive_sum(node->left, num, 0);
    if (node->right) recursive_sum(node->right, num, 1);
}

int sumOfLeftLeaves(TreeNode *root) {
    int num = 0;
    recursive_sum(root, num);
    return num;
}