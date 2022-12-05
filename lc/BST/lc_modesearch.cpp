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
map<int, int> rec;

void modeBST(TreeNode *node) {
    if (node == nullptr) return;
    modeBST(node->left);
    rec[node->val]++;
    modeBST(node->right);
}

vector<int> findMode(TreeNode *root) {
    modeBST(root);
    vector<int> res;
    int max_val = -1;
    for (auto it = rec.begin(); it != rec.end(); it++) {
        if (it->second > max_val) {
            max_val = it->second;
            res.resize(0);
            res.push_back(it->first);
        } else if (it->second == max_val) {
            res.push_back(it->first);
        }
    }
    return res;
}

int maxCount = 0; // 最大频率
int count = 0; // 统计频率
TreeNode *pre = NULL;
vector<int> result;

void searchBST(TreeNode *cur) {
    if (cur == NULL) return;

    searchBST(cur->left);       // 左
    // 中
    if (pre == NULL) { // 第一个节点
        count = 1;
    } else if (pre->val == cur->val) { // 与前一个节点数值相同
        count++;
    } else { // 与前一个节点数值不同
        count = 1;
    }
    pre = cur; // 更新上一个节点

    if (count == maxCount) { // 如果和最大值相同，放进result中
        result.push_back(cur->val);
    }

    if (count > maxCount) { // 如果计数大于最大值频率
        maxCount = count;   // 更新最大频率
        result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
        result.push_back(cur->val);
    }

    searchBST(cur->right);      // 右
    return;
}


vector<int> findMode(TreeNode *root) {
    count = 0;
    maxCount = 0;
    TreeNode *pre = NULL; // 记录前一个节点
    result.clear();

    searchBST(root);
    return result;
}

};