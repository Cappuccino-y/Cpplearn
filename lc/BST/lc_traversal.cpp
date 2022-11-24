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

void pre_traversal(TreeNode *node, vector<int> &res) {
    if (node == nullptr)
        return;
    res.push_back(node->val);
    pre_traversal(node->left, res);
    pre_traversal(node->right, res);

}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    pre_traversal(root, res);
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

