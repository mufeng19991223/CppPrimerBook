#include <bits/stdc++.h>

using namespace std;
//1.string
void test01()
{
    string str1(10, 'a');
    cout << str1;
}
//2.getline() ��������ʱ�Ŀհ׷�
void test02()
{
    string line2;
    while(getline(cin, line2))
    {
        cout << line2 << endl;
    }
}
//3.��Χ���for
void test03()
{
    string str1("hello world");
    for(auto c: str1)
    {
        cout << c << endl;
    }
    string str2("abcdef");
    //���ÿ��Ըı�string�������ַ���ֵ
    for(auto &c: str2)
    {
        c = toupper(c);
    }
    cout << str2;
}

//4.ʮ������תʮ��������
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
//6.iterator������ ���vector������һ������ ��ôֻ����const_iterator

//7.����arr
void test06()
{
    //�ں����� Ĭ�ϳ�ʼ��Ϊ���ֵ
    int a[19];
    for(int i = 0; i < 19; i++)
    {
        printf("%d ", a[i]);
    }
}

void test07()
{
    //��ʱ��С����Ϊ7 1����Ž�β���Ŀ��ַ�
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
    int j = p[1];  // p[1]�ȼ���*(p + 1);
    int k = p[-2]; // �ȼ���*(p - 2);
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

//�ַ��� 3.37
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

    //e�����ݽӵ���d����ֹ��'\0'��
    char d[20] = "123456";
    char e[20] = "abc";
    char *k1 = strcat(d, e);
    cout << k1 << endl;
    d[1] = '\0'; // '1\03456\0'
    char *k2 = strcat(d, e); // '1abc\06\0'
    cout << k2;
    // cout << strcat(d, e);
}

//������������
void test12()
{
    int arr[] = {11, 33, 44, 55, 66, 77};
    vector<int> v(arr + 1, arr + 4);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    } 
}

//���鿽������
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

//��ά���� ������ѭ���⣬����ѭ���Ŀ��Ʊ�����Ӧ������������
//�������鱻�Զ�ת��ָ�� c++ P105
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

//������ָ��
void test15()
{
    int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p)[4] = ia; //p 1 2 3 4
    // p = &ia[2]; //p 9 10 11 12
    cout << **p << endl;
    cout << p << " " << p + 1<< endl; // һ��һ��ȡ
    cout << *(*p) << " " << *(*p + 2) << endl; //һ��һ��ȡ
    cout << ia << " " << ia + 1 << endl; //һ��һ��ȡ
    cout << *(*ia) << " " << *(*ia + 1) << endl; //һ��һ��ȡ
    cout << *p << " " << *(p + 1) << endl; //һ��һ��ȡ
    // for(auto p = ia; p != ia + 3; p++)
    // {
    //     for(auto q = *p; q != *p + 4; q++) //*p����ڲ�ѭ��
    //     {
    //         cout << *q << " ";  //�൱��**p
    //     }
    //     cout << endl;
    // }
}
int main()
{
    test15();
    return 0;
}