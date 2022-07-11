#include <bits/stdc++.h>

using namespace std;
//1.string
void test01()
{
    string str1(10, 'a');
    cout << str1;
}
//2.getline() 保留输入时的空白符
void test02()
{
    string line2;
    while(getline(cin, line2))
    {
        cout << line2 << endl;
    }
}
//3.范围语句for
void test03()
{
    string str1("hello world");
    for(auto c: str1)
    {
        cout << c << endl;
    }
    string str2("abcdef");
    //引用可以改变string对象中字符的值
    for(auto &c: str2)
    {
        c = toupper(c);
    }
    cout << str2;
}

//4.十进制数转十六进制数
const string hexdigits = "0123456789ABCDEF";
void test04()
{
    string res;
    string::size_type n;
    while(cin >> n)
    {
        if(n < hexdigits.size())
        {
            res += hexdigits[n];
        }
    }
    cout << res;
}

//5.vector
void test05()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    } 
    // for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    // {
    //     cout << *it << " ";
    // }

}
//6.iterator迭代器 如果vector对象是一个常量 那么只能用const_iterator

//7.数组arr
void test06()
{
    //在函数内 默认初始化为随机值
    int a[19];
    for(int i = 0; i < 19; i++)
    {
        printf("%d ", a[i]);
    }
}

void test07()
{
    //此时大小至少为7 1个存放结尾处的空字符
    const char str[7] = "abcdef";
}

void test08()
{
    int a = 1, b = 2, c = 3;
    int* ptrs[10] = {&a, &b, &c};
    int *(&arr)[10] = ptrs;
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", &arr[i]);
    }
    int k[5] = {0, 1, 2, 3, 4};
    for(int f: k)
    {
        cout << f << " ";
    }
}

void test09()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = &a[2];
    int j = p[1];  // p[1]等价于*(p + 1);
    int k = p[-2]; // 等价于*(p - 2);
    cout << *p << " " << j << " " << k;
    cout << endl;
    int *p1 = begin(a), *p2 = end(a) - 2;
    cout << *p1 << " " << *p2;
    cout << endl;
    p1 += p2 - p1;
    cout << *p1 << " " << *p2;
    cout << endl;
    cout << sizeof(a) << " " << sizeof(*a);
}

//字符串 3.37
void test10()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
}

void test11()
{
    char a[] = "12345";
    char b[20], c[20] = "0000";
    strcpy(b, a);
    strcat(c, a);
    // cout << b << " " << c;

    //e的内容接到了d的终止符'\0'上
    char d[20] = "123456";
    char e[20] = "abc";
    char *k1 = strcat(d, e);
    cout << k1 << endl;
    d[1] = '\0'; // '1\03456\0'
    char *k2 = strcat(d, e); // '1abc\06\0'
    cout << k2;
    // cout << strcat(d, e);
}

//容器拷贝数组
void test12()
{
    int arr[] = {11, 33, 44, 55, 66, 77};
    vector<int> v(arr + 1, arr + 4);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    } 
}

//数组拷贝容器
void test13()
{
    int arr[100];
    vector<int> v;
    for(int i = 0; i < 100; i++)
    {
        v.push_back(i);
        arr[i] = v.at(i);
        cout << arr[i] << " ";
    }
}

//多维数组 除最内循环外，其他循环的控制变量都应该是引用类型
//避免数组被自动转成指针 c++ P105
void test14()
{
    constexpr size_t row = 3, col = 4;
    size_t cnt = 0;
    int ia[row][col];
    for(auto &r: ia)
    {
        for(auto &c: r)
        {
            c = cnt;
            cnt++;
        }
    }
}

//数组与指针
void test15()
{
    int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p)[4] = ia; //p 1 2 3 4
    // p = &ia[2]; //p 9 10 11 12
    cout << **p << endl;
    cout << p << " " << p + 1<< endl; // 一行一行取
    cout << *(*p) << " " << *(*p + 2) << endl; //一个一个取
    cout << ia << " " << ia + 1 << endl; //一行一行取
    cout << *(*ia) << " " << *(*ia + 1) << endl; //一个一个取
    cout << *p << " " << *(p + 1) << endl; //一行一行取
    // for(auto p = ia; p != ia + 3; p++)
    // {
    //     for(auto q = *p; q != *p + 4; q++) //*p解出内层循环
    //     {
    //         cout << *q << " ";  //相当于**p
    //     }
    //     cout << endl;
    // }
}
int main()
{
    test15();
    return 0;
}