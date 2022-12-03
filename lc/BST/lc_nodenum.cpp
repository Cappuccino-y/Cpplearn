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

int countNodes(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> temp;
    temp.push(root);
    int num = 0;
    while (!temp.empty()) {
        int size = temp.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = temp.front();
            temp.pop();
            num++;
            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }
    return num;
}

int countNodes(TreeNode *root) {
    if (root == nullptr) return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
    while (left) {  // 求左子树深度
        left = left->left;
        leftDepth++;
    }
    while (right) { // 求右子树深度
        right = right->right;
        rightDepth++;
    }
    if (leftDepth == rightDepth) {
        return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

