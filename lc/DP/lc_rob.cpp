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

vector<int> robTree(TreeNode *cur) {
    if (cur == nullptr) return vector<int>{0, 0};

    vector<int> res(2);
    if (cur->left) {
        vector<int> left = robTree(cur->left);
        res[0] = max(left[0], left[1]);
        res[1] = left[0];
    }
    if (cur->right) {
        vector<int> right = robTree(cur->right);
        res[0] += max(right[0], right[1]);
        res[1] += right[0];
    }
    res[1] += cur->val;
    return res;
}

class Solution {
public:
    unordered_map<TreeNode *, int> umap; // 记录计算过的结果
    int rob(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }
}


