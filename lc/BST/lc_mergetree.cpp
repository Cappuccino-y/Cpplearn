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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {

    TreeNode *root = nullptr;
    if (root1 && root2) root = new TreeNode(root1->val + root2->val);
    else if (root1 && !root2) root = new TreeNode(root1->val);
    else if (!root1 && root2) root = new TreeNode(root2->val);

    if (root1 && root2) {
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
    } else if (root1 && !root2) {
        root->left = mergeTrees(root1->left, nullptr);
        root->right = mergeTrees(root1->right, nullptr);
    } else if (!root1 && root2) {
        root->left = mergeTrees(nullptr, root2->left);
        root->right = mergeTrees(nullptr, root2->right);
    }
    return root;
}

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
    if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
    // 修改了t1的数值和结构
    t1->val += t2->val;                             // 中
    t1->left = mergeTrees(t1->left, t2->left);      // 左
    t1->right = mergeTrees(t1->right, t2->right);   // 右
    return t1;
}