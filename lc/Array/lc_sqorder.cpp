#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
    int length = nums.size();
    int *head = &nums[0];
    int *tail = &nums[length - 1];
    int i = length - 1;
    vector<int> result(length, 0);
    if (*head >= 0) {
        for (int i = 0; i < length; ++i) {
            result[i] = pow(nums[i], 2);
        }
        return result;
    } else if (*tail <= 0) {
        for (int i = 0; i < length; ++i) {
            result[i] = pow(nums[length - 1 - i], 2);
        }
        return result;
    }
    while (tail - head >= 0) {
        if (-*head > *tail) {
            result[i] = pow(*head, 2);
            head++;
        } else {
            result[i] = pow(*tail, 2);
            tail--;
        }
        i--;
    }
    return result;

}


int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};
    for (auto i : sortedSquares(nums)) {
        cout << i << " ";
    }
};
