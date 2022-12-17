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

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
    if (root->val == key) {
        // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        if (root->left == nullptr && root->right == nullptr) {
            ///! 内存释放
            delete root;
            return nullptr;
        }
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
        else if (root->left == nullptr) {
            auto retNode = root->right;
            ///! 内存释放
            delete root;
            return retNode;
        }
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
        else if (root->right == nullptr) {
            auto retNode = root->left;
            ///! 内存释放
            delete root;
            return retNode;
        }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
        else {
            TreeNode *cur = root->right; // 找右子树最左面的节点
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            TreeNode *temp = root->right;
            cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
            delete root;     // 返回旧root的右孩子作为新root
            return temp;
        }
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    if (root->val < key) root->right = deleteNode(root->right, key);
    return root;
}

int main() {
    TreeNode *as = new TreeNode(5);
    as->left = new TreeNode(3);
    as->right = new TreeNode(6);
    as->left->left = new TreeNode(2);
    as->left->right = new TreeNode(4);
    deleteNode(as, 3);

}


