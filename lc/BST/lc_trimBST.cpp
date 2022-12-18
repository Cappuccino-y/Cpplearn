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

class TreeNode {
private:

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
//TreeNode *trimBST(TreeNode *root, int low, int high) {
//    if (root == nullptr) return nullptr;
//    if (root->val < low) return trimBST(root->right, low, high);
//    if (root->val > high) return trimBST(root->left, low, high);
//
//    root->left = trimBST(root->left, low, high);
//    root->right = trimBST(root->right, low, high);
//    return root;
//}

TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == nullptr) return nullptr;
    if (root->val < low) {
        TreeNode *temp = root->right;
        delete root;
        return trimBST(temp, low, high);
    }
    if (root->val > high) {
        TreeNode *temp = root->left;
        delete root;
        return trimBST(temp, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main() {
    TreeNode *x = new TreeNode(1);
    x->right = new TreeNode(2);
    TreeNode *q = trimBST(x, 2, INT_MAX);
    int a = 3;
}
