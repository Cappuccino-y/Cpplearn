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

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

vector<int> partitionLabels(string s) {
    vector<int> res;
    vector<int> searched(26);
    unordered_map<char, int> rec;
    for (int i = 0; i < s.size(); i++) { // 统计每一个字符最后出现的位置
        rec[s[i] - 'a'] = i;
    }
    int bound = 0;
    int num = 0;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i <= bound) {
            bound = max(rec[s[i] - 'a'], bound);
            num++;
        } else {
            sum += num;
            res.push_back(num);
            num = 1;
            bound = rec[s[i] - 'a'];
        }
    }
    res.push_back(s.size() - sum);
    return res;
}

int main() {
    string s = "caedbdedda";
    partitionLabels(s);
}
