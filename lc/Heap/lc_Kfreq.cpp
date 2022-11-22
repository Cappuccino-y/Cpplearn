# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
#include  <queue>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

};

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq_rec;
    vector<int> res(k);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> temp;
    for (auto i :nums) {
        freq_rec[i]++;
    }
    for (auto it = freq_rec.begin(); it != freq_rec.end(); ++it) {
        temp.push(*it);
        if (temp.size() > k) {
            temp.pop();
        }
    }
    for (int i = 0; i < k; ++i) {
        res[i] = temp.top().first;
        temp.pop();
    }
    return res;
}

int main() {
    vector<int> a{1, 3, 2, 1};
    topKFrequent(a, 2);

}

