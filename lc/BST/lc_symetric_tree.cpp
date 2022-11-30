# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}


    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

bool Symetric_check(TreeNode *left, TreeNode *right) {
    if (left == nullptr ^ right == nullptr) return false;
    if (left == nullptr && right == nullptr) return true;
    if (left->val != right->val) return false;
    if (!Symetric_check(left->left, right->right)) return false;
    if (!Symetric_check(left->right, right->left)) return false;
    return true;
}

bool isSymmetric_recursive(TreeNode *root) {
    return Symetric_check(root->left, root->right);
}

bool isSymmetric_iteration(TreeNode *root) {
    queue<TreeNode *> process;
    process.push(root);
    while (!process.empty()) {
        vector<TreeNode *> comp;
        int size = process.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = process.front();
            process.pop();
            comp.push_back(node);
            if (node != nullptr) {
                process.push(node->left);
                process.push(node->right);
            }
        }
        for (int i = 0; i < comp.size() / 2; i++) {
            if (comp[i] == nullptr ^ comp[comp.size() - 1 - i] == nullptr) return false;
            if (comp[i] == nullptr && comp[comp.size() - 1 - i] == nullptr) continue;
            if (comp[i]->val != comp[comp.size() - 1 - i]->val) return false;
        }

    }
    return true;
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) return true;
    queue<TreeNode *> que;
    que.push(root->left);   // 将左子树头结点加入队列
    que.push(root->right);  // 将右子树头结点加入队列

    while (!que.empty()) {  // 接下来就要判断这两个树是否相互翻转
        TreeNode *leftNode = que.front();
        que.pop();
        TreeNode *rightNode = que.front();
        que.pop();
        if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
            continue;
        }

        // 左右一个节点不为空，或者都不为空但数值不相同，返回false
        if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
            return false;
        }
        que.push(leftNode->left);   // 加入左节点左孩子
        que.push(rightNode->right); // 加入右节点右孩子
        que.push(leftNode->right);  // 加入左节点右孩子
        que.push(rightNode->left);  // 加入右节点左孩子
    }
    return true;
}

int main() {
    TreeNode c = TreeNode(3);
    TreeNode d = TreeNode(4);
    TreeNode e = TreeNode(4);
    c.left = &d;
    c.right = &e;
    isSymmetric_iteration(&c);
}
