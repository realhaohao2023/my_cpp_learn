#include <iostream> // C++标准输入输出库

//支持使用cout和cin等函数，分别代替printf和scanf；

using namespace std; //std是C++标准库的命名空间

int a = 10;
char arr[] = "abcdef";
double b = 1.11;
float c = 0.0;

int main()
{
    cout<<"hello,world!"<<endl; //endl是换行符，相当于\n
    cout<<a<<endl;
    cout<<arr<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    return 0;
}