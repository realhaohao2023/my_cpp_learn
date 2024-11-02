#include <iostream> // C++标准输入输出库

using namespace std;

//auto关键字，自动推导变量类型

int testauto()
{
    return 10;
}

//不能使用auto的场景
//作为函数的参数
//auto Add(auto a, auto b)

//不能用来声明数组
//auto arr[] = {1, 2, 3, 4, 5};

int main()
{
    int a = 10;
    //声明auto变量时，必须初始化
    auto b = a; 
    auto c = 'c';
    auto d = testauto();

    //typedi(变量).name()可以查看变量的类型
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    return 0;

}