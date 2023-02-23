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
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};

int monotoneIncreasingDigits(int n) {
    int temp = n;
    int val = 0;
    vector<int> rec;
    while (temp != 0) {
        rec.push_back(temp % 10);
        temp /= 10;
    }
    for (int i = rec.size() - 1; i >= 0; --i) {
        if (i > 0 && rec[i] > rec[i - 1]) {
            int start_Index;
            val += rec[i] * pow(10, i);
            for (int j = i; j < rec.size(); j++) {
                if (j != rec.size() - 1 && rec[j + 1] <= rec[j] - 1) {
                    val += -1 * pow(10, j);
                    start_Index = j;
                    break;
                } else {
                    val -= rec[j] * pow(10, j);
                    if (j == rec.size() - 1) {
                        val += (rec[j] - 1) * pow(10, j);
                        start_Index = j;
                    }
                }
            }
            for (int j = start_Index - 1; j >= 0; --j) {
                val += 9 * pow(10, j);
            }
            break;
        } else val += rec[i] * pow(10, i);
    }
    return val;
}

int main() {
    monotoneIncreasingDigits(399443);
    Solution *a = new Solution();
    a->monotoneIncreasingDigits(32131);

}

