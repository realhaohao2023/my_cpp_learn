#include <iostream> // C++标准输入输出库

using namespace std;

//引用的基本使用：类型+& +引用变量名(对象名) = 引用实体;

int a = 10;
int& b = a; //b是a的引用，b是a的别名
int& c = b; //c是a的引用，c是a的别名
//引用在定义时必须初始化，一旦初始化后，就不可以更改了
//一个变量可以由多个引用
//int& d = a;
int& e = a;

//常引用
//const 修饰的为常量，不能绑定到一个可修改的引用上
const int ra = 10;
//int& rb = ra; //错误，常引用不能赋值给普通引用
const int& rb = ra; //正确，常引用可以赋值给常引用

int rb2 = 20;
const int& rb3 = rb2; //正确，普通变量可以赋值给常引用

double d = 1.11;
const int& rd = d; //正确，不同类型的变量可以赋值给常引用

//引用做参数,避免使用指针，引用更加简洁
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
//指针方法
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//引用做返回值
int& Add(int za, int zb)
{
    int zc = za + zb;
    return zc;
}


int main()
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    b = 20;//b是a的引用，b是a的别名，所以b改变，a也改变
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    c = 30;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    //打印abc的地址
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;

    int x = 1, y = 2;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    swap(x, y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //局部变量在函数结束后会被释放，所以不能返回局部变量的引用
    int& ret = Add(1, 2);//错误，返回值是局部变量的引用，局部变量在函数结束后会被释放
    //cout << ret << endl;
    cout << "-------------------" << endl; 
    return 0;
}