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

int findIndex(vector<int> &res, int &target) {
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == target) return i;
    }
    return -1;
}

void build(vector<int> &inorder, vector<int> &postorder, TreeNode *node) {
    int size = inorder.size();
    if (size == 0) return;
    int partition_inorder = findIndex(inorder, postorder[size - 1]);
    vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin() + partition_inorder);
    vector<int> left_postorder = vector<int>(postorder.begin(), postorder.begin() + left_inorder.size());
    if (left_inorder.size() != 0) {
        TreeNode *left_node = new TreeNode(left_postorder[left_postorder.size() - 1]);
        node->left = left_node;
    }

    vector<int> right_inorder = vector<int>(inorder.end() - size + partition_inorder + 1, inorder.end());
    vector<int> right_postorder = vector<int>(postorder.end() - 1 - right_inorder.size(), postorder.end() - 1);
    if (right_inorder.size() != 0) {
        TreeNode *right_node = new TreeNode(right_postorder[right_postorder.size() - 1]);
        node->right = right_node;
    }
    build(left_inorder, left_postorder, node->left);

    build(right_inorder, right_postorder, node->right);

    return;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
    build(inorder, postorder, root);
    return root;

}

TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.size() == 0) return NULL;

    // 后序遍历数组最后一个元素，就是当前的中间节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootValue);

    // 叶子节点
    if (postorder.size() == 1) return root;

    // 找到中序遍历的切割点
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }

    // 切割中序数组
    // 左闭右开区间：[0, delimiterIndex)
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    // [delimiterIndex + 1, end)
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

    // postorder 舍弃末尾元素
    postorder.resize(postorder.size() - 1);

    // 切割后序数组
    // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
    // [0, leftInorder.size)
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    // [leftInorder.size(), end)
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
}

TreeNode *buildTree_std(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) return NULL;
    return traversal(inorder, postorder);
}

int main() {
    vector<int> a{9, 3, 15, 20, 7};
    vector<int> b{9, 15, 7, 20, 3};

    TreeNode *c = buildTree(a, b);

    cout << c->val;

}


