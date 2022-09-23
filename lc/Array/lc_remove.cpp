#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    auto slow = nums.begin();
    auto fast = nums.begin();
    while (slow != nums.end()) {
        if (*slow == val) {
            while (fast != nums.end()) {
                if (*fast != val) {
                    *slow = *fast;
                    slow++;
                }
                fast++;
            }
        }
        if (fast == nums.end())
            break;
        fast++;
        slow++;
    }
    return (int) (slow - nums.begin());
}


int main() {
    vector<int> nums = {3, 2, 2, 3};
    int target = 3;
    cout << removeElement(nums, 3) << endl;
};
