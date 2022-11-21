#include<iostream>
#include<set>
#include <unordered_set>

using namespace std;


int main() {
    set<int> s;//定义一个空集合s
    s.insert(1);//向集合里面插入一个1；
    cout << *(s.begin()) << endl;//输出集合s的第一个元素（前面的星号表示要对指针取值）
    for (int i = 0; i < 6; i++) {
        s.insert(i);//向集合s里面插入i
    }
    for (auto it = s.begin(); it != s.end(); it++) {//用迭代器遍历集合s里面的每一个元素
        cout << *it << " ";
    }
    cout << endl << (s.find(2) != s.end()) << endl;//查找集合s中的值，如果结果等于s.end()表示未找到（因为s.end()表示s的最后一个元素的下一个元素所在的位置）
    cout << (s.find(10) != s.end()) << endl; // s.find(10) != s.end()表示能找到10这个元素
    s.erase(1); // 删除集合s中的1这个元素
    cout << (s.find(1) != s.end()) << endl; // 这时候元素1就应该找不到啦
    return 0;
}