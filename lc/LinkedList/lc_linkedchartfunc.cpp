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

ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
    dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
    ListNode *cur = dummyHead;
    while (cur->next != nullptr && cur->next->next != nullptr) {//此处利用了C++与的特性
        ListNode *tmp = cur->next; // 记录临时节点
        ListNode *tmp1 = cur->next->next->next; // 记录临时节点

        cur->next = cur->next->next;    // 步骤一
        cur->next->next = tmp;          // 步骤二
        cur->next->next->next = tmp1;   // 步骤三

        cur = cur->next->next; // cur移动两位，准备下一轮交换
    }
    return dummyHead->next;
}

ListNode *swapPairs_my(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return head;
    }
    ListNode *prev = head;
    ListNode *cur = head->next;
    ListNode *anchor = cur;
    ListNode *temp;
    while (cur != nullptr) {
        temp = cur->next;
        cur->next = prev;
        if (temp != nullptr) {
            if (temp->next == nullptr) {
                prev->next = temp;
            } else {
                prev->next = temp->next;
            }
            prev = temp;
            cur = temp->next;
        } else {
            prev->next = nullptr;
            break;
        }
    }
    return anchor;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {//可以用双指针固定位置来写
    if (head == nullptr) {
        return head;
    }
    ListNode *sentinel = new ListNode();
    sentinel->next = head;
    ListNode *first = sentinel;
    ListNode *second = first;
    while (first->next != nullptr) {
        first = first->next;
        n--;
    }
    while (n < 0) {
        second = second->next;
        n++;
    }
    second->next = second->next->next;
    return sentinel->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == headB) {
        return headA;
    }
    if (headA == nullptr | headB == nullptr) {
        return nullptr;
    }
    ListNode *A_1 = headA;
    ListNode *A_2 = headA;
    ListNode *B_1 = headB;
    ListNode *B_2 = headB;
    int count = 0;
    while (A_1->next != nullptr || B_1->next != nullptr) {
        if (A_1->next == nullptr) {
            while (B_1->next != nullptr) {
                B_1 = B_1->next;
                count++;
            }
            break;
        }
        if (B_1->next == nullptr) {
            while (A_1->next != nullptr) {
                A_1 = A_1->next;
                count--;
            }
            break;
        }
        A_1 = A_1->next;
        B_1 = B_1->next;
    }

    if (count >= 0) {
        for (int i = 0; i < count; i++) {
            B_2 = B_2->next;
        }
    } else if (count < 0) {
        for (int i = 0; i < -count; i++) {
            A_2 = A_2->next;
        }
    }
    while (B_2 != A_2 && B_2->next != nullptr) {
        B_2 = B_2->next;
        A_2 = A_2->next;
    }
    if (B_2 != A_2) {
        return nullptr;
    }
    return A_2;
}

ListNode *detectCycle(ListNode *head) {//注意跳跃式check
    if (head == nullptr)
        return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (slow->next != nullptr && fast->next->next != nullptr) {
        if (fast == slow) {
            ListNode *check = head;
            while (check != slow) {
                check = check->next;
                slow = slow->next;
            }
            return check;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return nullptr;
}

ListNode *detectCyclemy(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (slow->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        if (fast == slow) {
            ListNode *check = head;
            while (check != slow) {
                check = check->next;
                slow = slow->next;
            }
            return check;
        }

    }
    return nullptr;
}

int main() {
    ListNode *head = new ListNode(-4, NULL);
    ListNode *tmp = head;
    head = new ListNode(0, head);
    head = new ListNode(2, head);
    head = new ListNode(3, head);
    tmp->next = head->next;
    head = detectCycle(head);
    cout << head->val << endl;
//    for (int i = 0; i < 7; ++i) {
//        cout << head->val << endl;
//        head = head->next;
//    }
};
