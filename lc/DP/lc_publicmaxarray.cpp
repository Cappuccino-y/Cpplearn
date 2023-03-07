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

int findLength(vector<int> &A, vector<int> &B) {
    vector<int> dp(vector<int>(B.size() + 1, 0));
    int result = 0;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = B.size(); j > 0; j--) {
            if (A[i - 1] == B[j - 1]) {
                dp[j] = dp[j - 1] + 1;
            } else dp[j] = 0; // 注意这里不相等的时候要有赋0的操作
            if (dp[j] > result) result = dp[j];
        }
    }
    return result;
}

int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
    int res = 0;
    for (int i = 0; i < nums1.size(); ++i) {
        if (nums1[i] == nums2[0]) {
            dp[i][0] = 1;
            res = 1;
        }
    }
    for (int j = 0; j < nums2.size(); ++j) {
        if (nums2[j] == nums1[0]) {
            dp[0][j] = 1;
            res = 1;
        }
    }
    for (int i = 1; i < nums1.size(); ++i) {
        for (int j = 1; j < nums2.size(); ++j) {
            if (nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            if (dp[i][j] > res) res = dp[i][j];
        }
    }
    return res;
}

int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
    int res = 0;
    for (int i = 1; i < = nums1.size(); ++i) {
        for (int j = 1; j < = nums2.size(); ++j) {
            if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            if (dp[i][j] > res) res = dp[i][j];
        }
    }
    return res;
}
