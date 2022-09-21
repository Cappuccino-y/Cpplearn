#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else
            return mid;
    }
    return -1;
}

int navigate(vector<int> &nums, int index, int step) {
    int flag = nums[index];
    while (index >= 0 & index <= nums.size() - 1) {
        if (nums[index] != flag)
            return index - step;
        index = index + step;
    }
    return index - step;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int result = search(nums, target);
    if (result == -1)
        return vector<int>{-1, -1};
    int forward = navigate(nums, result, 1);
    int back = navigate(nums, result, -1);
    return vector<int>{back, forward};
}


int main() {
    vector<int> nums = {1};
    int target = 1;
    cout << *searchRange(nums, target).begin() << *searchRange(nums, target).rbegin() << endl;
};