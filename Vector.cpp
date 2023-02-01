#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

void func(int &a) { // 传⼊的是n的引⽤，相当于直接对n进⾏了操作，只不过在func函数中换了个名字叫a
    a = 99;
}

bool cmp(int a, int b) { // cmp函数返回的值是bool类型
    return a > b; // 从⼤到⼩排列
}

int main() {
    int n = 0;
    func(n); // n由0变成了99
    vector<int> v1(100, 7);
    vector<int> v2(133);

    cout << v1.size() << endl;
    v1.resize(8);
    cout << v1.size() << endl;
    const int m = v1[0];
    cout << m << endl;
    vector<int> a;// 定义的时候不指定vector的大小
    cout << a.size() << endl; // 这个时候size是0
    for (int i = 0; i < 10; i++) {
        a.push_back(i); // 在vector a的末尾添加元素i
    }

    vector<int> v(10);
    sort(v.begin(), v.end());// 因为这⾥没有传⼊参数cmp，所以按照默认，v从⼩到⼤排列
    int arr[10];
    sort(arr, arr + 10, cmp); // arr从⼤到⼩排列，因为cmp函数排序规则设置了从⼤到⼩

    cout << a.size() << endl; // 此时会发现a的size变成了10
    vector<int> b(15); // 定义的时候指定vector的大小，默认b元素都是0
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
        b[i] = 15;
    }
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    vector<int> c(20, 2); // 定义的时候指定vector的大小并把所有的元素赋一个指定的值
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    for (auto it = c.begin(); it != c.end(); it++) { // 使用迭代器访问vector
        cout << *it << " ";
    }
    vector<int> aqw(c.begin(), c.begin());
    cout << aqw.size() << endl;
    vector<vector<int>> temp;
    vector<int> caq;
    caq.resize(32, 0);
    vector<int> as123(caq);
    as123[0] = 3;
    cout << caq[0];
    return 0;
}