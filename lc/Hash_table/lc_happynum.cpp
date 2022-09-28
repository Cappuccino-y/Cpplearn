# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>

using namespace std;

bool isHappy(int n) {
    unordered_set<int> isloop;
    string res = to_string(n);
    int temp;
    while (temp != 1) {
        temp = 0;
        for (char s: res) {
            temp += pow(s - '0', 2);
        }
        if (isloop.find(temp) != isloop.end())
            return false;
        isloop.insert(temp);
        res = to_string(temp);
    }
    return true;
}

int main() {
    int m;

}

//

// Created by 幽幽的Yy on 2022/9/28.
//

