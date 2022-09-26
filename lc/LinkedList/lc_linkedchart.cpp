#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class MyLinkedList {
private:
    int val;
    MyLinkedList *next;
    MyLinkedList *prev;
public:
    MyLinkedList(int val) : val(val), next(nullptr), prev(nullptr) {
    }

    MyLinkedList() : val(0), next(nullptr), prev(nullptr) {
    }

    int get(int index) {
        if (next == nullptr) {
            return 0;
        }
        MyLinkedList *pointer = next;
        while (pointer->next != nullptr & index > 0) {
            pointer = pointer->next;
            index--;
        }
        if (index != 0) {
            return 0;
        }

        return pointer->val;
    }

    void addAtHead(int val) {
        MyLinkedList *newhead = new MyLinkedList(val);
        if (next != nullptr) {
            next->prev = newhead;
        }
        newhead->next = next;
        next = newhead;
        newhead->prev = this;

    }

    void addAtTail(int val) {
        MyLinkedList *pointer = this;
        while (pointer->next != nullptr)
            pointer = pointer->next;
        pointer->next = new MyLinkedList(val);
        pointer->next->prev = pointer;
    }

    void addAtIndex(int index, int val) {
        if (next == nullptr) {
            if (index == 0) {
                addAtTail(val);
                return;
            } else
                return;
        }
        MyLinkedList *pointer = next;
        while (pointer->next != nullptr & index > 0) {
            pointer = pointer->next;
            index--;
        }
        if (index != 0) {
            return;
        }

        if (pointer->prev == this) {
            addAtHead(val);
        } else if (pointer->next == nullptr) {
            addAtTail(val);
        } else {
            MyLinkedList *insertion = new MyLinkedList(val);
            insertion->next = pointer;
            insertion->prev = pointer->prev;
            insertion->prev->next = insertion;
            pointer->prev = insertion;
        }


    }

    void deleteAtIndex(int index) {
        if (next == nullptr) {
            return;
        }
        MyLinkedList *pointer = next;
        while (pointer->next != nullptr & index > 0) {
            pointer = pointer->next;
            index--;
        }
        if (index != 0) {
            return;
        }

        if (pointer->next != nullptr) {
            pointer->next->prev = pointer->prev;
        }
        pointer->prev->next = pointer->next;

    }
};

int main() {
    MyLinkedList *asd = new MyLinkedList();
    asd->addAtHead(4);
    cout << asd->get(1) << endl;


}