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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) return nullptr;
    if (root->val == p->val || root->val == q->val) return root;

    TreeNode *sig1 = lowestCommonAncestor(root->left, p, q);
    TreeNode *sig2 = lowestCommonAncestor(root->right, p, q);
    if (sig1 && sig2) {
        return root;
    }
    if (sig1 && !sig2)
        return sig1;
    return sig2;
}

