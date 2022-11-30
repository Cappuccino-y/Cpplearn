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

void search_depth(TreeNode *node, vector<string> &res, vector<int> &rec) {
    rec.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
        string temp;
        for (int i = 0; i < rec.size() - 1; ++i) {
            temp += to_string(rec[i]) + "->";
        }
        temp += to_string(rec[rec.size() - 1]);
        res.push_back(temp);
        return;
    }
    if (node->left) {
        search_depth(node->left, res, rec);
        rec.resize(rec.size() - 1);
    }
    if (node->right) {
        search_depth(node->right, res, rec);
        rec.resize(rec.size() - 1);
    }


}


vector<string> binaryTreePaths_my(TreeNode *root) {
    vector<string> res;
    vector<int> rec;
    search_depth(root, res, rec);
    return res;
}

void traversal(TreeNode *cur, string path, vector<string> &result) {
    path += to_string(cur->val); // 中
    if (cur->left == NULL && cur->right == NULL) {
        result.push_back(path);
        return;
    }
    if (cur->left) traversal(cur->left, path + "->", result); // 左
    if (cur->right) traversal(cur->right, path + "->", result); // 右
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    string path;
    if (root == NULL) return result;
    traversal(root, path, result);
    return result;

}

