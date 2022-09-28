#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length())
        return result;
    string temp;
    set<string> check;
    sort(p.begin(), p.end());
    for (int i = 0; i < s.length() - p.length() + 1; i++) {
        temp = s.substr(i, p.length());
        sort(temp.begin(), temp.end());
        check.insert(temp);
        if (check.find(p) != check.end()) {
            result.push_back(i);
        }
        check.erase(temp);
    }
    return result;
}
