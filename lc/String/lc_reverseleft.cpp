# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

void reverse(string &s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseLeftWords(string s, int n) {
    reverse(s, 0, s.size() - 1);
    reverse(s, 0, s.size() - 1 - n);
    reverse(s, s.size() - n, s.size() - 1);
    return s;
}


int main() {

}