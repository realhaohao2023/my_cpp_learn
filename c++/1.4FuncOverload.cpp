#include <iostream> // C++标准输入输出库

using namespace std;

//C++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数的形参列表(参数个数 或 类型 或 顺序)必须不同，即参数个数，参数顺序，参数类型三者有一个不同即可。常用来处理实现功能类似数据类型不同的问题

//参数类型不同
int Add(int a, int b)
{
    return a + b;
}

int Add(double a, double b)
{
    return a + b;
}

//参数个数不同
int Func(int a)
{
    return a;
}

int Func(int a, int b)
{
    return a + b;
}

//参数顺序不同
int Func(int a, double b)
{
    return a + b;
}

int Func(double a, int b)
{
    return a + b;
}

//返回值不同,不可以重载,需要参数不同，编译器才能区分
int f(int a, int b)
{
    cout << "f(int a, int b)" << endl;
    return 0;
}

char f(double a, int b)
{
    cout << "f(int a, int b)" << endl;
    return 'a';
}

int main()
{
    int a = Func(1);
    int b = Func(1, 2);
    double c = Func(1, 2.0);

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;

    return 0;
}