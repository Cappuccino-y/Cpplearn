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

int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    int ref_negative = -101;
    int ref_positive = 101;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            if (k > 0) {
                sum += -nums[i];
                k--;
            } else sum += nums[i];
            ref_negative = nums[i];
        } else if (nums[i] == 0) k = 0;
        else if (nums[i] > 0) {
            if (ref_positive > 100) ref_positive = nums[i];
            sum += nums[i];
        }
    }
    if (k % 2) {
        if (-ref_negative > ref_positive) {
            sum += -2 * ref_positive;
        } else {
            sum += 2 * ref_negative;
        }
    }
    return sum;
}

class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};
