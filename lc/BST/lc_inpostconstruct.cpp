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

int findIndex(vector<int> res, int target) {
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == target) return i;
    }
    return -1;
}

void build(vector<int> inorder, vector<int> postorder, TreeNode *node) {
    int size = inorder.size();

    // if (size<3) {
    //     if (size==2&&partition_inorder==0) node->right= new TreeNode(postorder[0]);
    //     if (size==2&&partition_inorder==1)  node->left= new TreeNode(postorder[0]);
    //     return;
    // }
    int partition_inorder = findIndex(inorder, postorder[size - 1]);
    int partition_postorder = findIndex(postorder, inorder[partition_inorder - 1]);

    vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin() + partition_inorder);
    vector<int> left_postorder = vector<int>(postorder.begin(), postorder.begin() + partition_postorder + 1);
    if (left_inorder.size() != 0) {
        TreeNode *left_node = new TreeNode(left_postorder[left_postorder.size() - 1]);
        node->left = left_node;
    }

    vector<int> right_inorder = vector<int>(inorder.end() - size + partition_inorder + 1, inorder.end());
    vector<int> right_postorder = vector<int>(postorder.end() - size + partition_postorder + 1, postorder.end() - 1);
    if (right_inorder.size() != 0) {
        TreeNode *right_node = new TreeNode(right_postorder[right_postorder.size() - 1]);
        node->right = right_node;
    }
    if (left_inorder.size() != 0) build(left_inorder, left_postorder, node->left);

    if (right_inorder.size() != 0) build(right_inorder, right_postorder, node->right);

    return;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
    build(inorder, postorder, root);
    return root;

}

int main() {
    vector<int> a{9, 3, 15, 20, 7};
    vector<int> b{9, 15, 7, 20, 3};

    TreeNode *c = buildTree(a, b);

    cout << c->val;

}


