# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <stack>
# include <deque>

using namespace std;

int &trial(int &as) {
    return as;
}

int main() {
    int a = 2, b = 3;
    swap(a, b);
    cout << a << b << endl;
    vector<int> dqe = {3, 4, 21};
    int m = *min_element(dqe.begin(), dqe.end());
    cout << m;
    deque<int> ast(dqe.begin(), dqe.end());
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
    vector<string> as23(3);
    as23[0].append("3213");
    as23[0].resize(3);
    string qw2;
    cout << qw2;

//    cout << as[-1] << endl;
//    int a[4]{2, 3, 4, 5};
//    for (int m:a) {
//        cout << m << endl;
//    }
//    cout << *max_element(a, a + 4);
}
