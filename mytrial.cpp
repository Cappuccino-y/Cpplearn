# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>

using namespace std;

int main() {
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
    cout << as[-1] << endl;
}
