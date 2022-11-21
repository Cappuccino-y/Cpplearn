# include <set>
# include <map>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>
# include <cmath>
# include <stack>
#include <queue>

using namespace std;

class MyQueue {
private:
    stack<int> a;
    stack<int> b;
    queue<int> mn;


    void topple() {

        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        if (b.empty()) {
            topple();
        }
        int temp = b.top();
        b.pop();
        return temp;
    }

    int peek() {
        if (b.empty()) {
            topple();
        }
        return b.top();
    }

    bool empty() {
        return a.empty() && b.empty();
    }
};

class MyStack {
private:
    queue<int> In;
public:
    MyStack() {
    }

    void push(int x) {
        In.push(x);
    }

    int pop() {
        int temp;
        for (int i = 0; i < In.size() - 1; i++) {
            temp = In.front();
            In.pop();
            In.push(temp);
        }
        temp = In.front();
        In.pop();
        return temp;
    }

    int top() {
        int temp = pop();
        push(temp);
        return temp;
    }

    bool empty() {
        return In.size() == 0;
    }
};

int main() {

    vector<stack<int>> rec(3, stack<int>());
    MyQueue a = MyQueue();
    cout << rec[0].top() << endl;

}

