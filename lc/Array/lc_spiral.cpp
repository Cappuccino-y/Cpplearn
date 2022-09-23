#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int times = n % 2 == 0 ? 2 * n : 2 * n - 1;
    int direction;
    int circle;
    int m = 1;
    vector<vector<int>> smatrix(n, vector<int>(n));
    for (int i = 0; i < times; ++i) {
        direction = i % 4;
        circle = i / 4;
        if (n - 2 * circle - 1 == 0) {
            smatrix[circle][circle] = m++;
        } else {
            switch (direction) {
                case 0:
                    for (int j = 0; j < n - 2 * circle - 1; ++j) {
                        smatrix[circle][circle + j] = m++;
                    }
                    break;
                case 1:
                    for (int j = 0; j < n - 2 * circle - 1; ++j) {
                        smatrix[circle + j][n - 1 - circle] = m++;
                    }
                    break;
                case 2 :
                    for (int j = 0; j < n - 2 * circle - 1; ++j) {
                        smatrix[n - 1 - circle][n - 1 - circle - j] = m++;
                    }
                    break;
                case 3:
                    for (int j = 0; j < n - 2 * circle - 1; ++j) {
                        smatrix[n - 1 - circle - j][circle] = m++;
                    }
                    break;
            }
        }
    }
    return smatrix;
}

int main() {
    int n = 3;
    vector<vector<int>> smatrix(n, vector<int>(n));
    generateMatrix(2);
    cout << smatrix[0][0];
};
