#include <bits/stdc++.h>
#include <vector>                     
using namespace std;


//左值: 对象的身份(在内存中的位置)  右值: 对象的值(内容)

//* ++
void test01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    vector<int>::iterator it = v1.begin();
    cout << *(it++)<< " ";
    cout << *(it++)<< " ";
    cout << *(it++)<< " ";
    cout << (*it)++<< " ";
    cout << ++*it<< " ";
    cout << *it++<< " ";
}

//二进制输出
void test02(unsigned int number) {
    if (number >> 1) {
        test02(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

//得到数组元素个数
void test03()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << sizeof(a) / sizeof(int) << endl;
    int x[10]; int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p);
}

//逗号运算符
void test04()
{
    int a = 10;
    int x = 0, y = 0;
    a = 10 ? ++x, ++y: --x, --y;
    cout << x << " " << y;
}
int main()
{
    test04();
    return 0;
}