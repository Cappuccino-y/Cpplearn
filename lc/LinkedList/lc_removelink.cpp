#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

struct ListNode {

    int val;

    ListNode *next;


    ListNode() : val(0), next(nullptr) {}


    ListNode(int x) : val(x), next(nullptr) {}


    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList_o(ListNode *head) {
    if (head == nullptr)
        return head;
    vector<int> record;
    ListNode *pointer = head;
    while (pointer != nullptr) {
        record.push_back(pointer->val);
        pointer = pointer->next;
    }
    pointer = head;
    for (auto it = record.rbegin(); it != record.rend(); it++) {
        pointer->val = *it;
        pointer = pointer->next;
    }
    return head;
}

ListNode *reverse_iterative(ListNode *pre, ListNode *cur) {
    if (cur == nullptr) {
        return pre;
    }
    ListNode *temp = cur;
    cur = temp->next;
    temp->next = pre;
    pre = temp;
    return reverse_iterative(pre, cur);
}

ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
        return head;
    return reverse_iterative(nullptr, head);
}

ListNode *removeElements(ListNode *head, int val) {
    ListNode *last = NULL;
    ListNode *scan = head;
    while (scan != NULL) {
        if (scan->val == val) {
            if (last == NULL) {
                head = scan->next;
                scan = head;
                continue;
            }
            last->next = scan->next;
        } else {
            last = scan;
        }
        scan = scan->next;
    }
    return head;
}

int main() {
    ListNode *head = new ListNode(6, NULL);
    head = new ListNode(5, head);
    head = new ListNode(4, head);
    head = new ListNode(3, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);
    head = reverseList(head);
    for (int i = 0; i < 7; ++i) {
        cout << head->val << endl;
        head = head->next;
    }
};
