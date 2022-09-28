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
    if (asd.find(1) != asd.end()) {
        cout << "yes";
    }
}
