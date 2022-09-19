#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s; // 定义⼀个空栈s
    for (int i = 0; i < 6; i++) {
        s.push(i); // 入栈 将元素i压⼊栈s中
    }
    cout << s.top() << endl; // 访问s的栈顶元素
    cout << s.size() << endl; // 输出s的元素个数
    s.pop(); // 出栈 移除栈顶元素
    return 0;
}