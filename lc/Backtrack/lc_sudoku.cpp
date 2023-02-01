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

bool Valid(vector<vector<char>> &board, int i, int j, char target) {
    for (int row = 0; row < 9; ++row) {
        if (board[row][j] == target) return false;
    }
    for (int col = 0; col < 9; ++col) {
        if (board[i][col] == target) return false;
    }

    int group_row = 3 * (i / 3);
    int group_col = 3 * (j / 3);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + group_row][col + group_col] == target) return false;
        }
    }
    return true;
}

bool Sudoku_recur(vector<vector<char>> &board, int index) {
    if (index == 81) {
        return true;
    }

    int i = index / 9;
    int j = index % 9;
    if (board[i][j] == '.') {
        for (char target = '1'; target <= '9'; ++target) {
            if (Valid(board, i, j, target)) {
                board[i][j] = target;
                if (Sudoku_recur(board, index + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    } else return Sudoku_recur(board, index + 1);
}


void solveSudoku(vector<vector<char>> &board) {
    Sudoku_recur(board, 0);
}

