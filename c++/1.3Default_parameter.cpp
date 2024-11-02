#include <iostream> // C++标准输入输出库

using namespace std; //std是C++标准库的命名空间
//全缺省参数，参数给一个默认值，调用函数时不输入就赋默认值
void Func(int a = 10, int b = 20, int c = 30) 
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
//传进去的实参必须是从左向右传的，而且必须连续的
//错误示范：Func(1, , 3);

//半缺省参数，参数部分初始化
void Func2(int a, int b = 10, int c = 20)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}


int main()
{
    Func(1, 2, 3);
    cout<<"-------------------"<<endl;
    Func(1, 2);
    cout<<"-------------------"<<endl;
    Func(1);
    cout<<"-------------------"<<endl;
    Func();
    cout<<"-------------------"<<endl;
    return 0;
}