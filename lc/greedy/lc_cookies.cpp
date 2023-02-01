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

int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int num = 0;
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
        if (g[i] > s[j]) {
            j++;
        } else {
            num++;
            i++;
            j++;
        }
    }
    return num;
}


int main() {
    vector<int> g{3, 12, 312, 433, 13, 354, 5, 1, 2, 3};
    vector<int> s{1, 1, 9, 2, 1, 3, 56, 64, 23, 123, 4234};
    int c = findContentChildren(g, s);
    cout << c << endl;

}
