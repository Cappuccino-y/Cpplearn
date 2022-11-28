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
    stack<TreeNode *> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();                       // 中
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);           // 右（空节点不入栈）
        if (node->left) st.push(node->left);             // 左（空节点不入栈）
    }
    return result;
}

vector<int> preorderTraversal_iteration_my(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> temp;
    TreeNode *now;
    if (root == nullptr) return res;
    temp.push(root);
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

vector<int> inorderTraversal_unify(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node != NULL) {
            st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
            if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

            st.push(node);                          // 添加中节点
            st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

            if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
        } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
            st.pop();           // 将空节点弹出
            node = st.top();    // 重新取出栈中元素
            st.pop();
            result.push_back(node->val); // 加入到结果集
        }
    }
    return result;
}

vector<int> inorderTraversal_iteration(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) { // 指针来访问节点，访问到最底层
            st.push(cur); // 将访问的节点放进栈
            cur = cur->left;                // 左
        } else {
            cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            st.pop();
            result.push_back(cur->val);     // 中
            cur = cur->right;               // 右
        }
    }
    return result;
}

vector<int> postorderTraversal_iteration_my(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> temp;
    TreeNode *now;
    if (root == nullptr) return res;
    temp.push(root);
    while (!temp.empty()) {
        now = temp.top();
        temp.pop();
        while (now != nullptr) {
            res.push_back(now->val);
            temp.push(now->left);
            now = now->right;
        }
    }
    reverse(res.begin(), res.end());
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

