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

class Solution {
private:
    vector <vector<string>> result;

// n 为输入的棋盘大小
// row 是当前递归到棋盘的第几行了
    void backtracking(int n, int row, vector <string> &chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
                chessboard[row][col] = 'Q'; // 放置皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯，撤销皇后
            }
        }
    }

    bool isValid(int row, int col, vector <string> &chessboard, int n) {
        // 检查列
        for (int i = 0; i < row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

public:
    vector <vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

using namespace std;
vector<vector<string>> res;
vector<string> cur;
vector<vector<int>> rec;

void forbid(int i, int j, int n, vector<pair<int, int>> &change) {
    for (int index = 0; index < n; ++index) {
        if (!rec[i][index]) {
            rec[i][index] = 1;
            change.push_back(pair<int, int>({i, index}));
        }
        if (!rec[index][j]) {
            rec[index][j] = 1;
            change.push_back(pair<int, int>({index, j}));
        }
        if (i > j) {
            if (i - j + index < n && !rec[i - j + index][index]) {
                rec[i - j + index][index] = 1;
                change.push_back(pair<int, int>({i - j + index, index}));
            }
        } else {
            if (j - i + index < n && !rec[index][j - i + index]) {
                rec[index][j - i + index] = 1;
                change.push_back(pair<int, int>({index, j - i + index}));
            }
        }

        if (i + j < n) {
            if (i + j - index > -1 && !rec[i + j - index][index]) {
                rec[i + j - index][index] = 1;
                change.push_back(pair<int, int>({i + j - index, index}));
            }
        } else {
            if (j - (n - 1 - i) + index < n && !rec[n - 1 - index][j - (n - 1 - i) + index]) {
                rec[n - 1 - index][j - (n - 1 - i) + index] = 1;
                change.push_back(pair<int, int>({n - 1 - index, j - (n - 1 - i) + index}));
            }
        }
    }
}

void recur_NQueens(int n, int num) {
    if (num == 0) {
        res.push_back(cur);
        return;
    }
    vector<pair<int, int>> change;
    int i = n - num;
    for (int j = 0; j < n; j++) {
        if (!rec[i][j]) {
            cur[i].insert(j, "Q");
            forbid(i, j, n, change);
            recur_NQueens(n, num - 1);
            for (int m = 0; m < change.size(); ++m) {
                rec[change[m].first][change[m].second] = 0;
            }
            cur[i].erase(j, 1);
            change.clear();
        }
    }
    return;

}


vector<vector<string>> solveNQueens(int n) {
    rec.resize(n, vector<int>(n, 0));
    string basic;
    basic.insert(0, n - 1, '.');
    cur.resize(n, basic);
    recur_NQueens(n, n);
    return res;
}


int main() {
    vector<vector<string>> awe;
    awe = solveNQueens(4);
    int m = 3;
}