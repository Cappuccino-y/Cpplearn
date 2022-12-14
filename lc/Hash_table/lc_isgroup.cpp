#include <vector>
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

bool isAnagram(string s, string t) {
    vector<int> records(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        ++records[s[i] - 'a'];
    }
    for (int i = 0; i < t.length(); ++i) {
        --records[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (records[i] != 0)
            return false;
    }
    return true;
}

vector<vector<string>> groupAnagrams_my(vector<string> &strs) {
    vector<vector<string>> result;
    vector<bool> isconnect(strs.size(), false);
    if (strs.size() == 1) {
        result.push_back(vector<string>(1, strs[0]));
        return result;
    }
    int m = 0;
    for (int i = 0; i < strs.size(); ++i) {
        if (isconnect[i]) {
            continue;
        }
        result.push_back(vector<string>(1, strs[i]));
        for (int j = i + 1; j < strs.size(); ++j) {
            if (isconnect[j]) {
                continue;
            }
            if (isAnagram(strs[i], strs[j])) {
                result[m].push_back(strs[j]);
                isconnect[j] = true;
            }
        }
        m++;
    }
    return result;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    map<string, vector<string>> M;
    for (int i = 0; i < strs.size(); i++) {
        string key = strs[i];
        sort(key.begin(), key.end());
        M[key].push_back(strs[i]);
    }
    for (auto ite = M.begin(); ite != M.end(); ite++)
        res.push_back(ite->second);
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << groupAnagrams(strs)[0][0] << endl;

}