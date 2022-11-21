# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
# include <stack>
# include <queue>

using namespace std;

bool isValid(string s) {
    char temp;
    stack<char> rec;
    for (auto i : s) {
//        此处可以 使用右括号的形式代替比较
        if (i == '(' || i == '[' || i == '{')
            rec.push(i);
        else {
            if (rec.empty() || (i - rec.top() != 1 & i - rec.top() != 2))
                return false;
            rec.pop();
        }
    }
    if (!rec.empty())
        return false;
    return true;
}
//
// Created by yydyy77 on 2022/11/20/020.
//

