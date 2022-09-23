#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

//没有必要写开（即可以选择终端循环中写入灵活延展）
//int minSubArrayLen(int target, vector<int> &nums) {
//    int sum = 0;
//    int len = 0;
//    int i = 0;
//    int j = 0;
//    int flag = 0;
//    int length = nums.size();
//    int min_len = INT_MAX;
//    while (j < length) {
//        while (sum < target) {
//            if (j == length) {
//                len = INT_MAX;
//                flag = 1;
//                break;
//            }
//            sum += nums[j];
//            j++;
//        }
//        if (flag == 1) {
//            break;
//        }
//        len = j - i;
//        if (len < min_len)
//            min_len = len;
//
//        while (sum >= target) {
//            sum -= nums[i];
//            i++;
//        }
//        len = j - i + 1;
//        if (len < min_len)
//            min_len = len;
//    }
//    if (min_len <= length)
//        return min_len;
//    return 0;
//}

int minSubArrayLen(int target, vector<int> &nums) {
    int sum = 0;
    int len = 0;
    int j = 0;
    int length = nums.size();
    int min_len = INT_MAX;
    for (int i = 0; i < length; ++i) {
        while (sum < target) {
            if (j == length) {
                len = INT_MAX;
                break;
            }
            sum += nums[j];
            j++;
        }
        len = len == INT_MAX ? INT_MAX : j - i;
        if (len < min_len)
            min_len = len;
        sum -= nums[i];
    }
    if (min_len <= length)
        return min_len;
    return 0;
}

int minSubArrayLen_standard(int s, vector<int> &nums) {
    int result = INT32_MAX;
    int sum = 0; // 滑动窗口数值之和
    int i = 0; // 滑动窗口起始位置
    int subLength = 0; // 滑动窗口的长度
    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
        while (sum >= s) {
            subLength = (j - i + 1); // 取子序列的长度
            result = result < subLength ? result : subLength;
            sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
        }
    }
    // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return result == INT32_MAX ? 0 : result;
}

int main() {
    set<int> asd = {};
    asd.insert(3);
    asd.insert(3);
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << asd << endl;
};
