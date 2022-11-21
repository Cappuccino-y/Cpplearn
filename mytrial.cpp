# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <stack>

using namespace std;

int &trial(int &as) {
    return as;
}

int main() {

    vector<int> dqe = {3, 4, 21};
    vector<int> asdaq(dqe.begin(), dqe.end() - 1);
    stack<int> asq1;
    asq1.push(34);
    asq1.pop();
    cout << asq1.top();
    unordered_map<int, int> asd;
    cout << asd[1]++ << endl;
    cout << asd[1] << endl;
    int val = -3;
    int val2 = 2;
    cout << to_string(val) + to_string(val2) << endl;
    if (asd.find(1) != asd.end()) {
        cout << "yes" << endl;
    }
    string as;
    as.append("yasdasdl2317");
    cout << trial(val) << endl;
    cout << &val << endl;
    cout << asdaq[1] << endl;
    as.resize(3);
    stack<int> aasd;

    int c = stoi("-3");
    cout << c << endl;

//    cout << as[-1] << endl;
//    int a[4]{2, 3, 4, 5};
//    for (int m:a) {
//        cout << m << endl;
//    }
//    cout << *max_element(a, a + 4);
}
