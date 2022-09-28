# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> records;
    for (char i: magazine) {
        records[i]++;
    }
    for (char i:ransomNote) {
        if (records.find(i) == records.end() || records[i] == 0)
            return false;
        records[i]--;
    }
    return true;
}

