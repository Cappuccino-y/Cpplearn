# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

//
// Created by 幽幽的Yy on 2022/11/28.
//
vector<vector<int>> levelOrder_iteration(TreeNode *root) {
    queue < TreeNode * > temp;
    vector<vector<int>> res;
    if (!root) return res;
    temp.push(root);
    while (!temp.empty()) {
        int size = temp.size();
        vector<int> order;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = temp.front();
            temp.pop();
            order.push_back(node->val);
            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
        res.push_back(order);
    }
    return res;
}

void order(TreeNode *cur, vector<vector<int>> &result, int depth) {
    if (cur == nullptr) return;
    if (result.size() == depth) result.push_back(vector<int>());
    result[depth].push_back(cur->val);
    order(cur->left, result, depth + 1);
    order(cur->right, result, depth + 1);
}

vector<vector<int>> levelOrder_recursive(TreeNode *root) {
    vector<vector<int>> result;
    int depth = 0;
    order(root, result, depth);
    return result;
}

int main() {
    vector<int> a;
    a.em
}

