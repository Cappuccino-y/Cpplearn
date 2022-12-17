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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int convert(TreeNode *node, int ref) {
    if (node == nullptr) return 0;

    int sum = convert(node->right, ref);
    sum += node->val;
    node->val = sum + ref;
    sum += convert(node->left, node->val);

    return sum;
}

TreeNode *convertBST(TreeNode *root) {
    convert(root, 0);
    return root;
}

private:
int pre = 0; // 记录前一个节点的数值
void traversal(TreeNode *cur) { // 右中左遍历
    if (cur == NULL) return;
    traversal(cur->right);
    cur->val += pre;
    pre = cur->val;
    traversal(cur->left);
}

public:

TreeNode *convertBST(TreeNode *root) {
    pre = 0;
    traversal(root);
    return root;
}