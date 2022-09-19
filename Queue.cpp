#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q; // 定义⼀个空队列q
    for (int i = 0; i < 6; i++) {
        q.push(i); //入队 将i的值依次压⼊队列q中
    }
    cout << q.front() << " " << q.back() << endl; // 访问队列的队⾸元素和队尾元素
    cout << q.size() << endl; // 输出队列的元素个数
    q.pop(); // 出队 移除队列的队⾸元素
    return 0;
}