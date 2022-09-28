#include <iostream>
#include <bitset>
#include <cctype>
#include<iomanip>
#include <cmath>

using namespace std;

int main() {
    auto x = 32;
    bitset<5> b("11"); //5表示5个⼆进位
    // 初始化⽅式：
    // bitset<5> b; 都为0
    // bitset<5> b(u); u为unsigned int，如果u = 1,则被初始化为10000
    // bitset<5> b(s); s为字符串，如"1101" -> 10110
    // bitset<5> b(s, pos, n); 从字符串的s[pos]开始，n位⻓度
    for (int i = 0; i < 5; i++)
        cout << b[i];
    cout << endl << b.any(); //b中是否存在1的⼆进制位
    cout << endl << b.none(); //b中不存在1吗？
    cout << endl << b.count(); //b中1的⼆进制位的个数
    cout << endl << b.size(); //b中⼆进制位的个数
    cout << endl << b.test(2) << endl; //测试下标为2处是否⼆进制位为1
    b.set(3); //把b的下标为4处置1
//    b.reset(); //所有位归零
//    b.reset(3); //b的下标3处归零
//    b.flip(); //b的所有⼆进制位逐位取反
    unsigned long a = b.to_ulong(); //b转换为unsigned long类型
    cout << a << endl;
    for (int i = 0; i < 5; i++)
        cout << b[i];

    char c;
    cin >> c;
    if (isalpha(c)) {
        cout << "c is alpha";
    }
    c = 'A';
    char t = tolower(c); // 将c字符转化为⼩写字符赋值给t，如果c本身就是⼩写字符也没有关系
    cout << t; // 此处t为'a'
//    isalpha 字母（包括大写、小写）
//islower（小写字母）
//isupper（大写字母）
//isalnum（字母大写小写+数字）
//isblank（space和\t）
    string s1 = to_string(123); // 将123这个数字转成字符串
    s1.e
    cout << s1 << endl;
    string s2 = to_string(4.5); // 将4.5这个数字转成字符串
    cout << s2 << endl;
    cout << s1 + s2 << endl; // 将s1和s2两个字符串拼接起来并输出
    printf("%s\n", (s1 + s2).c_str()); // 如果想⽤printf输出string，得加⼀个.c_str()/isspace（space、\t、\r、\n）
    string str = "123";
    a = stoi(str);
    cout << a << endl;
    str = "123.44";
    double ba = stod(str);
    cout << ba << endl;
    cout << stoi(str) << endl;
    cout << fixed << setprecision(1) << ba << endl;
    return 0;
}