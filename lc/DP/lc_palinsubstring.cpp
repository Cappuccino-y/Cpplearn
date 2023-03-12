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

int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    int res = 0;
    for (int i = s.size() - 1; i > -1; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
    }
    return res;
}

