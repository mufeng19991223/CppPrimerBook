#include <bits/stdc++.h>

using namespace std;

//只声明不定义
extern int i;
//声明并定义
int j;

// 1.类型
void test01()
{
    long double a = 1.546354854131651561;
    unsigned int b = 102;
    // unsigned char c = -256;
    // cout << c;
    //死循环
    // for (unsigned x = 10; x >= 0; x--)
    // {
    //     cout << x << " ";
    // }

    unsigned u1 = 10, u2 = 42;
    int i1 = 10, i2 = 42;
    cout << u2 - u1 << endl;
    cout << u1 - u2 << endl;
    cout << i2 - i1 << endl;
    cout << i1 - i2 << endl;
    cout << i1 - u1 << endl;
    cout << u1 - i1 << endl;
}

// 2.字面值常量
void test02()
{
    char a = 'A';
    char b[10] = "ABC\0ED";
    char *c = "ABCDE";
    cout << "strlen(b) " << strlen(b) << endl;
    cout << "strlen(c) " << strlen(c) << endl;
    cout << "sizeof(a) " << sizeof(a) << endl;
    cout << "sizeof(b) " << sizeof(b) << endl;
    cout << "sizeof(c) " << sizeof(c) << endl;
    cout << U"3.14159";
}

// 3.变量
void test03()
{
    //列表初始化
    int a1 = 1;
    int a2 = {2};
    int a3(3);
    int a4{4};
    printf("%d\t%d\t%d\t%d\t", a1, a2, a3, a4);
    //函数体内部默认初始化
    int a5;
    cout << a5 << "\t";
    int a6 = 3.14;
    cout << a6 << "\t";
    ;
    //建议初始化每一个内置类型的变量
    int a = 2;
    a <<= 10;
    cout << a;
    //作用域
    int i = 100, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += i;
    }
    cout << sum; // 45
}

// 4.引用
void test04()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.11;
    r2 = r1;
    i = r2;
    r1 = d;
    cout << i << "\t" << r1 << "\t" << d << "\t" << r2;
    int a = 10;
    //左右值
    int &a1 = a; //左值用的是对象的身份  右值用的是对象的内容(值)
    int &&a2 = 10;
    cout << a1 << " " << a2;
}

// 5.指针
void test05()
{
    //建议初始化所有指针
    int a = 10;
    int b = 11;
    int *p1 = &a;
    cout << "p1= " << p1 << endl;
    cout << "*p1= " << *p1 << endl;
    int *p2 = &a + 1;
    cout << "p2= " << p2 << endl;
    cout << "*p2= " << *p2 << endl;
    int &c = *p1;
    cout << "&c= " << &c << endl;
    int *p3 = nullptr;
    cout << "p3= " << p3 << endl;
    //赋值和指针
    int val1 = 20;
    int *p4 = &val1;
    *p4 = 10;
    cout << "val1= " << val1 << endl;

    int val2 = 40;
    int *p5 = &val2;
    *p5 = *p5 * *p5;
    cout << "val2= " << val2 << endl;
    cout << "*p5= " << *p5 << endl;
    // void* 可以存放任意对象的地址
}

// 6.指向指针的引用
void test06()
{
    //p7将影响p6的值
    int val3 = 50;
    int *p6;
    int *&p7 = p6;
    cout << "&p6= " << &p6 << endl;
    cout << "&p7= " << &p7 << endl;
    cout << "p7= " << p7 << endl;
    cout << "&val3= " << &val3 << endl;
    cout << "*&p7= " << *&p7 << endl;
    cout << "-----------------------" << endl;
    p7 = &val3;
    cout << "&p6= " << &p6 << endl;  //地址不改变
    cout << "&p7= " << &p7 << endl; //地址不改变
    cout << "*p6= " << *p6 << endl;
    cout << "*p7= " << *p7 << endl;
    cout << "&val3= " << &val3 << endl;
    cout << "p7= " << p7 << endl;
    cout << "*&p7= " << *&p7 << endl; //对指针的引用改变  等于 val3的地址
    *p7 = 0;
    cout << "-----------------------" << endl;
    cout << "&p6= " << &p6 << endl;
    cout << "&p7= " << &p7 << endl;
    cout << "*p6= " << *p6 << endl;
    cout << "*p7= " << *p7 << endl;
    cout << "val3= " << val3 << endl;
    cout << "p7= " << p7 << endl;
    cout << "&val3= " << &val3 << endl;
    cout << "*&p7= " << *&p7 << endl;
}

//const与指针
void test07()
{
    int a = 10;
    int b = 20;
    //指向常量的指针  不可以改变对象的值
    const int *p1 = &a;
    p1 = &b;
    cout << "p1 = " << *p1 << endl;
    //常量指针  不可以改变地址
    int *const p2 = &a;
    *p2 = 30;
    cout << "p2 = " << *p2 << endl;
    //指向常量的常量指针 都不可以改变
    const int *const p3 = &b;
    cout << "p3 = " << *p3 << endl;
    
    //2.30 - 2.31
    // const int v2 = 0;
    // int v1 = v2;
    // int *k1 = &v1, &r1 = v1;
    // const int *k2 = &v2, *const k3 = &b, &r2 = v2;
    // r1 = v2;
    // k1 = k2;
    // k2 = k1;
    // k1 = k3;
    // k2 = k3;
}
int c = 2;
constexpr int a = 10;
//string类型不能定义成constexpr 
//指针必须初始化为nullptr或0或存储于某个固定地址的对象
//constexpr只对指针有效 与对指针指向的变量无效
constexpr const int *p1 = &a; //相当于指向常量对象的常量指针
constexpr int *p2 = &c;       //相当于常量指针
const int *p = NULL;          //指向整形常量的指针
int null = 0;
// constexpr int *p = &null;

//类型别名
typedef long long LL;
typedef double DB;
typedef int *pstring;

//auto类型
int aaas()
{
    return 10;
}
void test08()
{
    // int i = 10;
    // const int ci = i, &cr = ci;
    // auto e = &ci; //e是一个指向常量的指针
    const int i = 42;
    auto j = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;
    //j int k int p int * j2 const int k2 const int;
    int a  = 10;
    decltype(aaas()) k = 0;
    cout << k;
}


int main()
{
    test08();
    return 0;
}