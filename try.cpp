#include <iostream>

const int as = 9999;
using namespace std;

int main() {
//    int n;
//    cin >> n;
//
//    cout << "hello ,lyy" << n + 1 << endl;
//    for (int i = 0; i < n; i++) { //这个i只在for循环里面有用，出了这个for循环就失效了
//        cout << i << endl;
//        bool m = -32;
//        if (m)
//            cout << m;
//    }
//    string s = "hello c++";//赋值字符串
//    string s1 = s;
//    string s2 = s + s1; //字符串拼接直接用+号就可以
//    string s3;
//    cin >> s3;//读入字符串
//    cout << s << endl << s1 << endl << s2 << endl << s3 << endl;//输出字符串
    int n;
    cin >> n;
    cout << n << endl;
    string s;//定义一个空字符串s
    cout << getchar();
    getline(cin, s);//读取一行的字符串，包括空格
    cout << s << endl;
    cout << s.length();//输出字符串s的长度
    cout << s.substr(0, 4);
    struct stu {
        int grade;
        float score;
    };
    struct stu arr1[10]; // C语 ⾔⾥⾯需要写struct
    stu arr2[10];// C++⾥⾯不⽤写
    return 0;
}
