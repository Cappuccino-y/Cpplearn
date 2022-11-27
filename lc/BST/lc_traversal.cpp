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

class TreeNode {
private:

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void pre_traversal_recursive(TreeNode *node, vector<int> &res) {
    if (node == nullptr)
        return;
    res.push_back(node->val);
    pre_traversal_recursive(node->left, res);
    pre_traversal_recursive(node->right, res);

}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    pre_traversal_recursive(root, res);
    return res;
}

vector<int> preorderTraversal_iteration(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> temp;
    TreeNode *now;
    if (root == nullptr)
        return res;
    else {
        temp.push(root->right);
        temp.push(root->left);
        res.push_back(root->val);
    }
    while (!temp.empty()) {
        now = temp.top();
        temp.pop();
        while (now != nullptr) {
            res.push_back(now->val);
            temp.push(now->right);
            now = now->left;
        }
    }
    return res;

}

int main() {
    TreeNode a = TreeNode(34);
    TreeNode b = TreeNode(23);
    a.left = &b;
    cout << a.left->val << endl;

}

//
// Created by yydyy77 on 2022/11/23/023.
//

